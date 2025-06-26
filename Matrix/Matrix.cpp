#include <fstream>
#include <iostream>
#include <math.h>
#include "Matrix.hpp"
#include <iomanip>
// #include "Function/polynomial.hpp"



using namespace std;
Matrix::Matrix()
{
    rows = 0;
    cols = 0;
}

Matrix::Matrix(int r, int c) : rows(r), cols(c), data(r, vector<double>(c, 0))
{
}

Matrix::Matrix(const Matrix &mat) : rows(mat.rows), cols(mat.cols), data(mat.data)
{
}

Matrix::~Matrix()
{
}

void Matrix::inputFileMatrix(const std::string File)
{
    ifstream inputFile(File);

    if (!inputFile.is_open())
    {
        cerr << "Error: Unable to open input file!" << endl;
        return;
    }

    int newRows, newCols;
    inputFile >> newRows >> newCols;

    // Update matrix dimensions
    rows = newRows;
    cols = newCols;

    // Resize the vector with zero-initialization
    data.resize(rows, vector<double>(cols, 0.0));

    // Read matrix values from the file
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (!(inputFile >> data[i][j]))
            {
                cerr << "Error: Not enough data in input file!" << endl;
                inputFile.close();
                return;
            }
        }
    }

    inputFile.close();
    cout << "Matrix read from file successfully!" << endl;
}

// Addition
Matrix Matrix::AddMatrix(const Matrix &mat) const
{
    if (rows != mat.rows || cols != mat.cols)
    {
        return Matrix(0, 0); // return empty matrix
    }

    Matrix result(rows, cols);
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            result.data[i][j] = this->data[i][j] + mat.data[i][j];

    return result;
}

// Substraction
Matrix Matrix::SubMatrix(const Matrix &mat) const
{
    if (rows != mat.rows || cols != mat.cols)
    {
        return Matrix(); // Return empty matrix
    }

    Matrix result(rows, cols);
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            result.data[i][j] = this->data[i][j] - mat.data[i][j];

    return result;
}

// Multiplication
Matrix Matrix::MultMatrix(const Matrix &mat)
{
    if (cols != mat.rows)
    {
        throw std::runtime_error("Error: Matrices cannot be multiplied, incompatible dimensions!");
    }

    Matrix result(rows, mat.cols); // Create result matrix of size (rows x mat.cols)

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < mat.cols; j++)
        {
            result.data[i][j] = 0;         // Initialize result cell
            for (int k = 0; k < cols; k++) // Multiply row elements by column elements
            {
                result.data[i][j] += this->data[i][k] * mat.data[k][j];
            }
        }
    }

    return result;
}

// Identity
bool Matrix::isIdentity() const
{
    if (rows != cols)
        return false;

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (i == j && data[i][j] != 1)
            {
                return false;
            }
        }
    }
    return true;
}

// Gauss Elimination
Matrix Matrix::GaussElimination(const Matrix &mat)
{
    if (rows != mat.rows || mat.cols != 1)
    {
        cerr << "Error: Augment matrix must have the same number of rows and exactly one column." << endl;
        return *this;
    }

    // Augment the matrix
    Matrix obj1(*this); // Copy current matrix

    obj1.cols += 1; // Increase column count

    for (int i = 0; i < rows; i++)
    {
        // Check if row size is as expected before augmentation
        if (obj1.data[i].size() == obj1.cols - 1)
        {
            obj1.data[i].push_back(mat.data[i][0]); // Append column
        }
        else
        {
            return *this;
        }
    }

    int n = obj1.rows;

    for (int i = 0; i < n; i++)
    {
        int maxIndex = i;

        for (int k = i + 1; k < n; k++)
        {
            if (fabs(obj1.data[k][i]) > fabs(obj1.data[maxIndex][i]))
            {
                maxIndex = k;
            }
        }

        if (maxIndex != i)
        {
            std::swap(obj1.data[i], obj1.data[maxIndex]);
        }

        if (fabs(obj1.data[i][i]) < 1e-9)
        {
            obj1;
        }

        for (int j = i + 1; j < obj1.cols; j++)
        {
            obj1.data[i][j] /= obj1.data[i][i];
        }

        obj1.data[i][i] = 1;

        for (int k = i + 1; k < n; k++)
        {
            double factor = obj1.data[k][i];

            for (int j = i; j < obj1.cols; j++)
            {
                obj1.data[k][j] -= factor * obj1.data[i][j];
            }
        }
    }

    // Back-substitution to find the solution
    Matrix result(n, 1);

    for (int i = n - 1; i >= 0; i--)
    {
        result.data[i][0] = obj1.data[i][n];

        for (int j = i + 1; j < n; j++)
        {
            result.data[i][0] -= obj1.data[i][j] * result.data[j][0];
        }
    }

    return result;
}

// Upper Matrix
Matrix Matrix::UpperMatrix()
{
    Matrix U(*this); // Copy the current matrix
    int n = U.rows;

    for (int i = 0; i < n; i++)
    {
        // Find the maximum pivot in the current column
        int maxRow = i;
        for (int k = i + 1; k < n; k++)
        {
            if (fabs(U.data[k][i]) > fabs(U.data[maxRow][i]))
            {
                maxRow = k;
            }
        }

        // Swap rows in U
        if (fabs(U.data[maxRow][i]) < 1e-9)
        {
            std::cerr << "Warning: Zero pivot detected at row " << i << ". Skipping this row.\n";
            continue; // Skip processing for this pivot
        }

        // Eliminate entries below the pivot
        for (int k = i + 1; k < n; k++)
        {
            double factor = U.data[k][i] / U.data[i][i];
            for (int j = i; j < U.cols; j++)
            {
                U.data[k][j] -= factor * U.data[i][j];
            }
        }
    }

    return U;
}

// Lower Matrix
Matrix Matrix::LowerMatrix()
{
    Matrix L(rows, cols); // Initialize L as an identity matrix
    Matrix U(*this);      // Copy the original matrix to work on U
    int n = rows;

    for (int i = 0; i < n; i++)
    {
        // Find the maximum pivot in the current column
        int maxRow = i;
        for (int k = i + 1; k < n; k++)
        {
            if (fabs(U.data[k][i]) > fabs(U.data[maxRow][i]))
            {
                maxRow = k;
            }
        }

        // Swap rows in U and corresponding rows in L
        if (fabs(U.data[maxRow][i]) < 1e-9)
        {
            std::cerr << "Warning: Zero pivot detected at row " << i << ". Skipping this row.\n";
            continue; // Skip processing for this pivot
        }
        // Eliminate entries below the pivot
        for (int k = i + 1; k < n; k++)
        {
            double factor = U.data[k][i] / U.data[i][i];
            L.data[k][i] = factor;
            for (int j = i; j < U.cols; j++)
            {
                U.data[k][j] -= factor * U.data[i][j];
            }
        }
    }

    // Set diagonal elements of L to 1
    for (int i = 0; i < n; i++)
    {
        L.data[i][i] = 1;
    }

    return L;
}


// Cholesky Decomposition
Matrix Matrix::CholeskyDecomposition() const
{
    if (rows != cols)
        throw runtime_error("Error: Matrix must be square for Cholesky decomposition!");

    Matrix L(rows, cols);

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            double sum = 0.0;

            if (j == i) // Diagonal elements
            {
                for (int k = 0; k < j; k++)
                    sum += L.data[j][k] * L.data[j][k];

                if (data[j][j] - sum < 0)
                    throw runtime_error("Error: Matrix is not positive definite!");

                L.data[j][j] = sqrt(data[j][j] - sum);
            }
            else // Off-diagonal elements
            {
                for (int k = 0; k < j; k++)
                    sum += L.data[i][k] * L.data[j][k];

                L.data[i][j] = (data[i][j] - sum) / L.data[j][j];
            }
        }
    }
    return L;
}

Matrix Matrix::transpose() const
{
    Matrix trans(cols, rows);
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            trans.data[j][i] = data[i][j];

    return trans;
}


// Display the matrix
void Matrix::displayMatrix() const
{
    cout << "Matrix: " << endl;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
            cout << data[i][j] << " ";
        cout << endl;
    }
}




bool Matrix::isDiagonallyDominant() const
{
    for (int i = 0; i < rows; i++)
    {
        double diagonal = abs(data[i][i]);
        double rowSum = 0.0;

        for (int j = 0; j < cols; j++)
        {
            if (i != j)
                rowSum += abs(data[i][j]);
        }

        if (diagonal < rowSum)
            return false;
    }
    return true;
}

Matrix Matrix::MakeDominant()
{
    Matrix dominantMatrix(*this);
    int n = rows;

    std::vector<bool> used(rows, false);
    Matrix newMat(rows, cols);

    for (int i = 0; i < n; i++)
    {
        int bestRow = -1;

        for (int j = 0; j < n; j++)
        {
            if (!used[j])
            {
                double diag = fabs(data[j][i]);
                double rowSum = 0.0;

                for (int k = 0; k < n; k++)
                {
                    if (k != i)
                    {
                        rowSum += fabs(data[j][k]);
                    }
                }

                if (diag >= rowSum)
                {
                    bestRow = j;
                    break;
                }
            }
        }

        if (bestRow == -1) //no row is found intially 
        {
            throw std::runtime_error("Cannot rearrange matrix into a diagonally dominant form.");
        }

        newMat.data[i] = data[bestRow]; // Assign row
        used[bestRow] = true;
    }

    return newMat;
}


//Gauss Jacobi
void Matrix::GaussJacobi()
{
    Matrix obj1(*this);

    if (obj1.isDiagonallyDominant())
    {
        std::cout << "The given matrix is dominant." << std::endl;
        obj1.IterativeMethod();
    }
    else
    {
        Matrix Ans = obj1.MakeDominant();
        Ans.IterativeMethod();
    }
}

void Matrix::IterativeMethod()
{
    Matrix obj1(*this);

    double tolerance = 0.00001;
    double a = 0.0, y, x, z;
    double b = 0.0;
    double c = 0.0;
    int itr = 0;
    for (int i = 1; i < 20; i++)
    {
        x = obj1.func(0, b, c, 1, 2);
        y = obj1.func(1, a, c, 0, 2);
        z = obj1.func(2, a, b, 0, 1);

        double ans = a - x;

        if (ans < 0)
        {
            if ((ans * -1) <= tolerance)
                break;
        }
        else if ((ans) <= tolerance)
            break;

        cout << "Iteration " << itr << ": (" << a << ", " << b << ", " << c << ")" << endl;

        a = x;
        b = y;
        c = z;

        itr++;
    }
}



//Gauss Seidal
void Matrix::GaussSeidal()
{

    Matrix obj1(*this);

    if (obj1.isDiagonallyDominant())
    {
        std::cout << "Using Gauss-Seidel method:" << std::endl;
        obj1.IterativeMethodS();
    }
    else
    {
        Matrix Ans = obj1.MakeDominant();
        Ans.IterativeMethodS();
    }
}

void Matrix::IterativeMethodS()
{
    Matrix obj1(*this);
    double tolerance = 0.00001; // Convergence tolerance
    double a = 0.0, b = 0.0, c = 0.0; 
    int itr = 0;

    while (itr < 6) 
    {
        
        a = obj1.func(0, b, c, 1, 2); // Update `a` immediately
        b = obj1.func(1, a, c, 0, 2); // Use updated `a` for `b`
        c = obj1.func(2, a, b, 0, 1); // Use updated `a` and `b` for `c`

        // Check convergence
        double ans = fabs(a - b); 

        if (ans <= tolerance)
            break;

        // Output the current iteration and values
        cout << "Iteration " << itr << ": (" << a << ", " << b << ", " << c << ")" << endl;

        itr++;
    }
}

double Matrix::func(int row, double x, double y, int a, int b)
{
    Matrix obj1(*this);
    return ((obj1.data[row][3]) + (-1 * obj1.data[row][a] * x) + (-1 * obj1.data[row][b] * y)) / obj1.data[row][row];
}





int Matrix::size() const {
    return rows;
}