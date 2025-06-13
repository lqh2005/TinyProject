#include "LinearSystem.hpp"

LinearSystem::LinearSystem(const Matrix& A, const Vector& b) : mSize(A.getRows()) {
    assert(A.getRows() == A.getCols() && A.getRows() == b.getSize() && "Invalid dimensions");
    mpA = new Matrix(A);
    mpb = new Vector(b);
}

LinearSystem::~LinearSystem() {
    delete mpA;
    delete mpb;
}

Vector LinearSystem::Solve() const {
    // Triển khai khử Gauss với chọn hàng
    Matrix A(*mpA);
    Vector b(*mpb);
    Vector x(mSize);

    // Khử Gauss
    for (int k = 0; k < mSize - 1; ++k) {
        // Tìm pivot
        int maxRow = k;
        for (int i = k + 1; i < mSize; ++i) {
            if (std::abs(A(i + 1, k + 1)) > std::abs(A(maxRow + 1, k + 1))) {
                maxRow = i;
            }
        }
        // Hoán đổi hàng
        if (maxRow != k) {
            for (int j = 1; j <= mSize; ++j) {
                std::swap(A(k + 1, j), A(maxRow + 1, j));
            }
            std::swap(b(k + 1), b(maxRow + 1));
        }
        // Khử
        for (int i = k + 1; i < mSize; ++i) {
            double factor = A(i + 1, k + 1) / A(k + 1, k + 1);
            for (int j = k + 1; j <= mSize; ++j) {
                A(i + 1, j) -= factor * A(k + 1, j);
            }
            b(i + 1) -= factor * b(k + 1);
        }
    }
    // Thế ngược
    for (int i = mSize; i >= 1; --i) {
        double sum = 0.0;
        for (int j = i + 1; j <= mSize; ++j) {
            sum += A(i, j) * x(j);
        }
        x(i) = (b(i) - sum) / A(i, i);
    }
    return x;
}

PosSymLinSystem::PosSymLinSystem(const Matrix& A, const Vector& b) : LinearSystem(A, b) {
    // Kiểm tra đối xứng
    for (int i = 1; i <= mSize; ++i) {
        for (int j = i + 1; j <= mSize; ++j) {
            assert(std::abs(A(i, j) - A(j, i)) < 1e-10 && "Matrix must be symmetric");
        }
    }
}

Vector PosSymLinSystem::Solve() const {
    // Triển khai gradient liên hợp
    Vector x(mSize); // Nghiệm ban đầu = 0
    Vector r(*mpb);  // r = b - Ax, với x = 0 thì r = b
    Vector p(r);     // p = r
    Vector Ap(mSize);

    double rsold = 0.0;
    for (int i = 1; i <= mSize; ++i) {
        rsold += r(i) * r(i);
    }

    for (int iter = 0; iter < mSize; ++iter) {
        Ap = (*mpA) * p; // Ap = A * p
        double alpha = rsold;
        double pAp = 0.0;
        for (int i = 1; i <= mSize; ++i) {
            pAp += p(i) * Ap(i);
        }
        alpha /= pAp; // alpha = rsold / (p^T Ap)

        for (int i = 1; i <= mSize; ++i) {
            x(i) += alpha * p(i); // x = x + alpha * p
            r(i) -= alpha * Ap(i); // r = r - alpha * Ap
        }

        double rsnew = 0.0;
        for (int i = 1; i <= mSize; ++i) {
            rsnew += r(i) * r(i);
        }
        if (std::sqrt(rsnew) < 1e-10) break; // Điều kiện dừng

        double beta = rsnew / rsold;
        for (int i = 1; i <= mSize; ++i) {
            p(i) = r(i) + beta * p(i); // p = r + beta * p
        }
        rsold = rsnew;
    }
    return x;
}