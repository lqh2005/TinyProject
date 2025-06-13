#ifndef VECTOR_HPP
#define VECTOR_HPP
#include <cassert>
#include <iostream>
class Vector {
private:
    int mSize;
    double* mData;
public:
    Vector(int size);
    Vector(const Vector& other);
    ~Vector();
    Vector& operator=(const Vector& other);
    double& operator[](int index);
    double operator[](int index) const;
    double& operator()(int index);
    double operator()(int index) const;
    Vector operator+(const Vector& other) const;
    Vector operator-(const Vector& other) const;
    Vector operator*(double scalar) const;
    friend Vector operator*(double scalar, const Vector& vec);
    int getSize() const { return mSize; }
    void print() const;
};
#endif