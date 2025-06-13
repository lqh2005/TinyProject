#include "Matrix.hpp"
#include <cmath>

Matrix::Matrix(int rows, int cols) : mNumRows(rows), mNumCols(cols) {
    assert(rows > 0 && cols > 0 && "Matrix dimensions must be positive");
    mData = new double*[rows];
    for (int i = 0; i < rows; ++i) {
        mData[i] = new double[cols](); // Khởi tạo 0
    }
}

Matrix::Matrix(const Matrix& other) : mNumRows(other.mNumRows), mNumCols(other.mNumCols) {
    mData = new double*[mNumRows];
    for (int i = 0; i < mNumRows; ++i) {
        mData[i] = new double[mNumCols];
        for (int j = 0; j < mNumCols; ++j) {
            mData[i][j] = other.mData[i][j];
        }
    }
}

Matrix::~Matrix() {
    for (int i = 0; i < mNumRows; ++i) {
        delete[] mData[i];
    }
    delete[] mData;
}

Matrix& Matrix::operator=(const Matrix& other) {
    if (this != &other) {
        for (int i = 0; i < mNumRows; ++i) {
            delete[] mData[i];
        }
        delete[] mData;
        mNumRows = other.mNumRows;
        mNumCols = other.mNumCols;
        mData = new double*[mNumRows];
        for (int i = 0; i < mNumRows; ++i) {
            mData[i] = new double[mNumCols];
            for (int j = 0; j < mNumCols; ++j) {
                mData[i][j] = other.mData[i][j];
            }
        }
    }
    return *this;
}

double& Matrix::operator()(int i, int j) {
    assert(i >= 1 && i <= mNumRows && j >= 1 && j <= mNumCols && "Index out of bounds");
    return mData[i - 1][j - 1];
}

double Matrix::operator()(int i, int j) const {
    assert(i >= 1 && i <= mNumRows && j >= 1 && j <= mNumCols && "Index out of bounds");
    return mData[i - 1][j - 1];
}

Matrix Matrix::operator+(const Matrix& other) const {
    assert(mNumRows == other.mNumRows && mNumCols == other.mNumCols && "Matrix sizes must match");
    Matrix result(mNumRows, mNumCols);
    for (int i = 0; i < mNumRows; ++i) {
        for (int j = 0; j < mNumCols; ++j) {
            result.mData[i][j] = mData[i][j] + other.mData[i][j];
        }
    }
    return result;
}

// Tương tự cho operator-, operator*(Matrix), operator*(Vector), operator*(scalar)

void Matrix::print() const {
    for (int i = 0; i < mNumRows; ++i) {
        std::cout << "[ ";
        for (int j = 0; j < mNumCols; ++j) {
            std::cout << mData[i][j] << " ";
        }
        std::cout << "]" << std::endl;
    }
}

double Matrix::determinant() const {
    assert(mNumRows == mNumCols && "Matrix must be square");
    if (mNumRows == 2) {
        return mData[0][0] * mData[1][1] - mData[0][1] * mData[1][0];
    }
    return 0.0;
}

Matrix Matrix::inverse() const {
    assert(mNumRows == mNumCols && "Matrix must be square");
    int n = mNumRows;
    Matrix A(*this);
    Matrix I(n, n); // Ma trận đơn vị
    for (int i = 1; i <= n; ++i) I(i, i) = 1.0;

    // Khử Gauss
    for (int k = 1; k <= n; ++k) {
        int maxRow = k;
        for (int i = k + 1; i <= n; ++i) {
            if (std::abs(A(i, k)) > std::abs(A(maxRow, k))) maxRow = i;
        }
        if (maxRow != k) {
            for (int j = 1; j <= n; ++j) {
                std::swap(A(k, j), A(maxRow, j));
                std::swap(I(k, j), I(maxRow, j));
            }
        }
        double pivot = A(k, k);
        assert(std::abs(pivot) > 1e-10 && "Matrix is singular");
        for (int j = 1; j <= n; ++j) {
            A(k, j) /= pivot;
            I(k, j) /= pivot;
        }
        for (int i = 1; i <= n; ++i) {
            if (i != k) {
                double factor = A(i, k);
                for (int j = 1; j <= n; ++j) {
                    A(i, j) -= factor * A(k, j);
                    I(i, j) -= factor * I(k, j);
                }
            }
        }
    }
    return I;
}

Matrix Matrix::pseudoInverse() const {
    Matrix AT(mNumCols, mNumRows);
    for (int i = 1; i <= mNumRows; ++i) {
        for (int j = 1; j <= mNumCols; ++j) {
            AT(j, i) = (*this)(i, j);
        }
    }
    Matrix ATA = AT * (*this);
    Matrix ATA_inv = ATA.inverse();
    return ATA_inv * AT;
}