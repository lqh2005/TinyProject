#include "../include/LinearSystem.hpp"
#include <fstream>
#include <sstream>
#include <vector>
#include <random>
#include <cmath>
#include <iostream>

struct DataPoint {
    double MYCT, MMIN, MMAX, CACH, CHMIN, CHMAX;
    double PRP;
};

std::vector<DataPoint> readData(const std::string& filename) {
    std::vector<DataPoint> data;
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Lỗi: Không thể mở file " << filename << std::endl;
        return data;
    }
    std::string line;
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string vendor, model;
        double MYCT, MMIN, MMAX, CACH, CHMIN, CHMAX, PRP, ERP;
        char comma;
        std::getline(ss, vendor, ',');
        std::getline(ss, model, ',');
        ss >> MYCT >> comma >> MMIN >> comma >> MMAX >> comma >> CACH >> comma
           >> CHMIN >> comma >> CHMAX >> comma >> PRP >> comma >> ERP;
        data.push_back({MYCT, MMIN, MMAX, CACH, CHMIN, CHMAX, PRP});
    }
    file.close();
    return data;
}

void splitData(const std::vector<DataPoint>& data, std::vector<DataPoint>& train, std::vector<DataPoint>& test) {
    std::vector<int> indices(data.size());
    for (size_t i = 0; i < data.size(); ++i) indices[i] = i;
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(indices.begin(), indices.end(), g);
    size_t trainSize = data.size() * 0.8;
    for (size_t i = 0; i < trainSize; ++i) {
        train.push_back(data[indices[i]]);
    }
    for (size_t i = trainSize; i < data.size(); ++i) {
        test.push_back(data[indices[i]]);
    }
}

Vector linearRegression(const std::vector<DataPoint>& train) {
    int n = train.size();
    Matrix A(n, 6);
    Vector b(n);
    for (int i = 1; i <= n; ++i) {
        A(i, 1) = train[i - 1].MYCT;
        A(i, 2) = train[i - 1].MMIN;
        A(i, 3) = train[i - 1].MMAX;
        A(i, 4) = train[i - 1].CACH;
        A(i, 5) = train[i - 1].CHMIN;
        A(i, 6) = train[i - 1].CHMAX;
        b(i) = train[i - 1].PRP;
    }
    Matrix AT(6, n);
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= 6; ++j) {
            AT(j, i) = A(i, j);
        }
    }
    Matrix ATA = AT * A;
    Vector ATb = AT * b;
    LinearSystem ls(ATA, ATb);
    return ls.Solve();
}

double computeRMSE(const std::vector<DataPoint>& test, const Vector& x) {
    double mse = 0.0;
    for (const auto& point : test) {
        double pred = x(1) * point.MYCT + x(2) * point.MMIN + x(3) * point.MMAX +
                      x(4) * point.CACH + x(5) * point.CHMIN + x(6) * point.CHMAX;
        mse += (pred - point.PRP) * (pred - point.PRP);
    }
    return std::sqrt(mse / test.size());
}

int main() {
    auto data = readData("data\\machine.data");
    if (data.empty()) {
        std::cerr << "Không có dữ liệu để xử lý." << std::endl;
        return 1;
    }
    std::vector<DataPoint> train, test;
    splitData(data, train, test);
    Vector x = linearRegression(train);
    double rmse = computeRMSE(test, x);
    std::cout << "RMSE: " << rmse << std::endl;
    return 0;
}