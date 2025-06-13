#ifndef LINEAR_SYSTEM_HPP
#define LINEAR_SYSTEM_HPP

#include "Matrix.hpp"
#include "Vector.hpp"

class LinearSystem {
protected:
    int mSize;        
    Matrix* mpA;      
    Vector* mpb;     

private:
    LinearSystem(const LinearSystem&) = delete; 
    LinearSystem& operator=(const LinearSystem&) = delete;

public:
    LinearSystem(const Matrix& A, const Vector& b);
    virtual ~LinearSystem();
    virtual Vector Solve() const; 
};

class PosSymLinSystem : public LinearSystem {
public:
    PosSymLinSystem(const Matrix& A, const Vector& b);
    Vector Solve() const override; 
};

#endif