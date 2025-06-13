#ifndef MATRIX_HPP
#define MATRIX_HPP

#include "Vector.hpp"

class Matrix {
private:
    int mNumRows;     
    int mNumCols;     
    double** mData;   

public:
    // Hàm tạo
    Matrix(int rows, int cols);           
    Matrix(const Matrix& other);          
    ~Matrix();                            

    Matrix& operator=(const Matrix& other); 
    double& operator()(int i, int j);       
    double operator()(int i, int j) const;
    Matrix operator+(const Matrix& other) const; 
    Matrix operator-(const Matrix& other) const; 
    Matrix operator*(const Matrix& other) const; 
    Vector operator*(const Vector& vec) const;   
    Matrix operator*(double scalar) const;       
    friend Matrix operator*(double scalar, const Matrix& mat);

    // Phương thức
    int getRows() const { return mNumRows; }
    int getCols() const { return mNumCols; }
    double determinant() const;
    Matrix inverse() const;                
    Matrix pseudoInverse() const;          
    void print() const;                    
};

#endif