
#ifndef MATRIX_HPP
#define MATRIX_HPP


#include <iostream>
#include <vector>
using namespace std;

class Matrix
{
public:
    int rows, cols;
    vector<vector<double>> data;

    Matrix();
    Matrix(int r, int c);
    Matrix(const Matrix &mat);
    ~Matrix();

    void inputFileMatrix(const std::string File);
    Matrix AddMatrix(const Matrix &mat) const;
    Matrix SubMatrix(const Matrix &mat) const;
    Matrix MultMatrix(const Matrix &mat);
    bool isIdentity() const;
    Matrix GaussElimination(const Matrix &mat);
    Matrix UpperMatrix();
    Matrix LowerMatrix();
    Matrix CholeskyDecomposition() const;
    Matrix transpose() const;
    void displayMatrix() const;
    
    bool isDiagonallyDominant() const;
    Matrix MakeDominant();

    double func(int row, double x, double y, int a, int b);
    void IterativeMethod();
    void IterativeMethodS();

    void GaussSeidal();
    void GaussJacobi();
    
    std::vector<double> &operator[](int index)
    {
        return data[index];
    }
    const std::vector<double> &operator[](int index) const
    {
        return data[index];
    }
    int size() const;
    
};

#endif


// Commands for Run code
//  g++ main.cpp ./Matrix/matrix.cpp -o Myexe
//  Myexe



// g++ main.cpp Matrix/Matrix.cpp Polation.cpp -lm -o Myexe

