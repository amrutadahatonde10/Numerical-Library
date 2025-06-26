#include "./Root-Finding/Root_Finding.hpp"
 
int main()
{
   
    Root_Finding Root1, Root2, Root3;

    cout << "\n\nRoot_finding function called Bisection" << endl;
    double Ans1 = Root1.Bisection(0.0, 1.0);
    cout << "The root of the equation is: " << Ans1 << endl;
    
    return 0;
} 















 // cout << "\n\nRoot_finding function called Newton Raphson" << endl;
    // double Ans2 = Root2.Newton_Raphson(1.0);
    // cout << "The root of the equation is: " << Ans2 << endl;



    // cout << "\n\nRoot_finding function called Fixed Point" << endl;
    // double Ans3 = Root3.Fixed_Point(1.0);
    // cout << "The root of the equation is: " << Ans3 << endl;

















// #include <iostream>
// #include "./Matrix/Matrix.hpp"
// #include "Polation.hpp"

// int main()
// {
//     Matrix m1,m2;
//     m1.inputFileMatrix("Input/vec1polation.txt");
//     m2.inputFileMatrix("Input/vec2polation.txt");
//     double x = -1;

//     Polation ans;
//     double resultx = ans.lagrangeInterpolation(x,m1,m2);
    
//     cout << "Interpolated value at x = " << x << " is " << resultx << endl;
    
//     cout << "**************************************" << endl;

//     Matrix l1,l2;
//     l1.inputFileMatrix("Input/line1.txt");
//     l2.inputFileMatrix("Input/line2.txt");
//     double line = ans.LineParabola(l1,l2);

//     cout << "Ax2 + Bx + c  value = " << line << endl;


   
//     return 0;
// } 












 // Matrix l1,l2;
    // l1.inputFileMatrix("Input/line1.txt");
    // l2.inputFileMatrix("Input/line2.txt");
    // double line = ans.LineParabola(l1,l2);

    // cout << "Ax2 + Bx + c  value = " << line << endl;
    





// Complex Number

// #include "complex.hpp"
// using namespace std;

// int main() {
//     cmplx a, b, ans;  // Creates 4 complex number objects

//     a.real = 12;
//     a.img = 12;
//     b.real = 20;
//     b.img = 10;
//     // c.real = 5;
//     // c.img = 3;

//     cout << "a = ";
//     a.display();

//     cout << "b = ";
//     b.display();  

//     // cout << "c = ";
//     // c.display();

//     ans = a.add(b);  
//     cout << "Addition (a + b) ans = ";
//     ans.display();

//     ans = a.sub(b);  
//     cout << "Substraction (a - b) ans = ";
//     ans.display();


//     // c = c.add(ans);  
//     // cout << "Addition (a + b + c) ans = ";   
//     // c.display();  

//     return 0;
// }


















// //Matrix add, sub and Isidentity
// #include "./Matrix/Matrix.hpp"

// int main()
// {
//     // Read the first matrix from file
//     Matrix m1;
//     m1.inputFileMatrix("Input/input1.txt");
//     m1.displayMatrix();

//     // Read the second matrix from file
//     Matrix m2;
//     m2.inputFileMatrix("Input/input2.txt");
//     m2.displayMatrix();

//     // Addition
//     cout << "Addition Result:" << endl;
//     Matrix sumMatrix = m1.AddMatrix(m2);
//     sumMatrix.displayMatrix();

//     // Subtraction
//     cout << "Subtraction Result:" << endl;
//     Matrix subMatrix = m1.SubMatrix(m2);
//     subMatrix.displayMatrix();

//     //Identity
//     cout << "Checking if matrices is Identity:" << endl;

//     cout << "Matrix 1: " << (m1.isIdentity() ? "Identity" : "Not Identity") << endl;
//     cout << "Matrix 2: " << (m2.isIdentity() ? "Identity" : "Not Identity") << endl;

//     return 0;
// }


// #include "gauss_elimination.h"
// #include <iostream>
// #include <vector>

// int main() {
//     // Example system of equations:
//     // 3x + 2y - 2z = 3
//     // 2x + 4y + 3z = 15
//     // 5x - 3y + z = 14
//     std::vector<std::vector<double>> matrix = {
//         {3, 2, -2},
//         {2, 4, 3},
//         {5, -3, 1}
//     };

//     std::vector<double> b = {3, 15, 14};

//     try {
//         // Perform Gaussian elimination
//         gaussElimination(matrix, b);

//         // Perform back substitution
//         std::vector<double> solution = backSubstitution(matrix, b);

//         // Print the solution
//         std::cout << "Solution:" << std::endl;
//         for (size_t i = 0; i < solution.size(); ++i) {
//             std::cout << "x" << i + 1 << " = " << solution[i] << std::endl;
//         }

//     } catch (const std::exception& e) {
//         std::cerr << "Error: " << e.what() << std::endl;
//     }

//     return 0;
// }




// #include "./Matrix/Matrix.hpp"

// int main()
// {
//     // Read the first matrix from file
//     Matrix m1;
//     m1.inputFileMatrix("Input/input1.txt");
//     m1.displayMatrix();

//     // Read the second matrix from file
//     Matrix m12;
//     m12.inputFileMatrix("Input/input3.txt");
//     m12.displayMatrix();

    
//     // Read the second matrix from file
//     Matrix m2;
//     m2.inputFileMatrix("Input/input2.txt");
//     m2.displayMatrix();

//     // Read the third matrix from file
//     Matrix m3;
//     m3.inputFileMatrix("Input/n2.txt");
//     m3.displayMatrix();

//     // Addition
//     cout << "Addition Result:" << endl;
//     Matrix sumMatrix = m1.AddMatrix(m2);
//     sumMatrix.displayMatrix();

//     // Subtraction
//     cout << "Subtraction Result:" << endl;
//     Matrix subMatrix = m1.SubMatrix(m2);
//     subMatrix.displayMatrix();

//     //Identity
//     cout << "Checking if matrices is Identity:" << endl;

//     cout << "Matrix 1: " << (m1.isIdentity() ? "Identity" : "Not Identity") << endl;
//     cout << "Matrix 2: " << (m2.isIdentity() ? "Identity" : "Not Identity") << endl;

    
//     //Gauss Elimination
//     cout << "Gaussian Elimination Result:" << endl;
//     Matrix gaussMatrix3 = m1.GaussElimination(m12);
//     gaussMatrix3.displayMatrix();

//     m1.displayMatrix();

//     // Upper Matrix
//     cout << "Upper Matrix:" << endl;
//     Matrix upperMatrix = m1.UpperMatrix();
//     upperMatrix.displayMatrix();

//     // Lower Matrix
//     cout << "Lower Matrix:" << endl;
//     Matrix lowerMatrix = m1.LowerMatrix();
//     lowerMatrix.displayMatrix();

//     // LU
//     cout << "LU Decomposition Result:" << endl;
//     Matrix luMatrix = lowerMatrix.MultMatrix(upperMatrix);
//     luMatrix.displayMatrix();
    

//     return 0;
// }







//Gausssian Elimination LU
// #include "./Matrix/Matrix.hpp"

// int main()
// {

   
//     cout << "**************************************" << endl;
//     cout << "Read From File And Print It" << endl;
//     cout << "**************************************" << endl;

//     Matrix m2, m3;
//     // Read 49 X 49 Matrix
//     cout << "49 X 49 Matrix:" << endl;
//     m2.inputFileMatrix("Input/49l.txt");
//     m3.inputFileMatrix("Input/49r.txt");


//     cout << "**************************************" << endl;
//     cout << "Read File" << endl;
//     cout << "**************************************" << endl;

//     cout << "Gaussian Elimination Result:" << endl;
//     Matrix gaussMatrix3 = m2.GaussElimination(m3);
//     gaussMatrix3.displayMatrix();


//     Matrix U = m2.UpperMatrix();
//     U.displayMatrix();

//     Matrix L = m2.LowerMatrix();
//     L.displayMatrix();

//     Matrix A = L.MultMatrix(U);
//     A.displayMatrix();
    
    // Matrix m4, m5;
    // // Read 225 X 225 Matrix
    // cout << "225 X 225 Matrix:" << endl;
    // m4.inputFileMatrix("Input/225l.txt");
    // m5.inputFileMatrix("Input/225r.txt");


    // // 225 x 225
    // cout << "Gaussian Elimination Result:" << endl;
    // Matrix gaussMatrix5 = m4.GaussElimination(m5);
    // gaussMatrix5.displayMatrix();
    

    // cout << "**************************************" << endl;
    // cout << "X = L1.U1" << endl;
    // cout << "**************************************" << endl;

    // Matrix U1 = m4.UpperMatrix();
    // U1.displayMatrix();

    // Matrix L1 = m4.LowerMatrix();
    // L1.displayMatrix();

    // Matrix X = L1.MultMatrix(U1);
    // X.displayMatrix();
    

    // cout << "**************************************" << endl;
    // cout << "End" << endl;
    // cout << "**************************************" << endl;

//     return 0;
// }




// //Diagonally Dominant and cholesky LU
// #include "./Matrix/Matrix.hpp"

// int main()
// {
//     Matrix m3;
//     // Read the matrix from file
//     cout << "Input Matrix:" << endl;
//     m3.inputFileMatrix("Input/d4.txt");
//     m3.displayMatrix();

//     cout << "Checking if Matrix is Diagonally Dominant:" << endl;
//     if (m3.isDiagonallyDominant())
//         cout << "The matrix is diagonally dominant." << endl;
//     else
//         cout << "The matrix is NOT diagonally dominant." << endl;
//         cout << "**************************************" << endl;


//     Matrix m2;
//     // Read the matrix from file
//     cout << "Input Matrix:" << endl;
//     m2.inputFileMatrix("Input/m1.txt");
//     m2.displayMatrix();

//     cout << "**************************************" << endl;
//     cout << "Lower Triangular Matrix (L):" << endl;
//     Matrix LCholesky = m2.CholeskyDecomposition();
//     LCholesky.displayMatrix();

//     cout << "**************************************" << endl;
//     cout << "Upper Triangular Matrix (Lᵀ):" << endl;
//     Matrix UCholesky = LCholesky.transpose();
//     UCholesky.displayMatrix();

//     cout << "**************************************" << endl;
//     cout << "Ans:" << endl;
//     Matrix reconstructed = LCholesky.MultMatrix(UCholesky);
//     reconstructed.displayMatrix();

//     return 0;
// }


//Iterative Method - Gauss Jacobi/ Gauss Seidal
// #include <iostream>
// #include "./Matrix/Matrix.hpp"
// int main() {
    
//     Matrix m1;
    
//     cout << "Input Matrix:" << endl;
//     m1.inputFileMatrix("Input/input.txt");
//     m1.displayMatrix();

//     cout << "**************************************" << endl;
//     cout << "Gauss Jacobi:" << endl;
//     m1.GaussJacobi();

//     cout << "**************************************" << endl;
//     cout << "Gauss Seidal:" << endl;
//     m1.GaussSeidal();
    
//     return 0;
// }
