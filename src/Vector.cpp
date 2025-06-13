#include "Vector.hpp"

Vector::Vector(int size) : mSize(size) {
    assert(size > 0 && "Vector size must be positive");
    mData = new double[size](); // Khởi tạo 0
}

Vector::Vector(const Vector& other) : mSize(other.mSize) {
    mData = new double[mSize];
    for (int i = 0; i < mSize; ++i) {
        mData[i] = other.mData[i];
    }
}

Vector::~Vector() {
    delete[] mData;
}

Vector& Vector::operator=(const Vector& other) {
    if (this != &other) {
        delete[] mData;
        mSize = other.mSize;
        mData = new double[mSize];
        for (int i = 0; i < mSize; ++i) {
            mData[i] = other.mData[i];
        }
    }
    return *this;
}

double& Vector::operator[](int index) {
    assert(index >= 0 && index < mSize && "Index out of bounds");
    return mData[index];
}

double Vector::operator[](int index) const {
    assert(index >= 0 && index < mSize && "Index out of bounds");
    return mData[index];
}

double& Vector::operator()(int index) {
    assert(index >= 1 && index <= mSize && "Index out of bounds");
    return mData[index - 1];
}

double Vector::operator()(int index) const {
    assert(index >= 1 && index <= mSize && "Index out of bounds");
    return mData[index - 1];
}

Vector Vector::operator+(const Vector& other) const {
    assert(mSize == other.mSize && "Vector sizes must match");
    Vector result(mSize);
    for (int i = 0; i < mSize; ++i) {
        result.mData[i] = mData[i] + other.mData[i];
    }
    return result;
}

Vector Vector::operator-(const Vector& other) const {
    assert(mSize == other.mSize && "Vector sizes must match");
    Vector result(mSize);
    for (int i = 0; i < mSize; ++i) {
        result.mData[i] = mData[i] - other.mData[i];
    }
    return result;
}

Vector Vector::operator*(double scalar) const {
    Vector result(mSize);
    for (int i = 0; i < mSize; ++i) {
        result.mData[i] = mData[i] * scalar;
    }
    return result;
}

Vector operator*(double scalar, const Vector& vec) {
    return vec * scalar;
}

void Vector::print() const {
    std::cout << "[ ";
    for (int i = 0; i < mSize; ++i) {
        std::cout << mData[i] << " ";
    }
    std::cout << "]" << std::endl;
}