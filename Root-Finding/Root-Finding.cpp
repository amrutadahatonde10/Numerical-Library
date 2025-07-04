#include "./Root_Finding.hpp"
#include "../Function/polynomial.hpp"

Root_Finding::Root_Finding()
{
    TOL = 0.0001;
    Itr = 0;
}

// Bisection Method
double Root_Finding::Bisection(double a, double b)
{
    polynomial p1;

    while (fabs(a - b) > TOL)
    {
        double func_a = p1.functionPoly(a);
        double func_b = p1.functionPoly(b);

        if (func_a * func_b > 0)
        {
            std::cout << "No root in the given interval" << std::endl;
            return -1;
        }

        double ans_a = (a + b) / 2;
        double func_ans_a = p1.functionPoly(ans_a);

        if (fabs(func_ans_a) < TOL)
        {
            return ans_a;
        }

        if (func_a * func_ans_a < 0)
        {
            b = ans_a;
        }
        else
        {
            a = ans_a;
        }
    }
    return a;
}



// Newton-Raphson Method
// double Root_Finding::Newton_Raphson(double a)
// {
//     polynomial p1;
//     while (true)
//     {
//         double func = p1.functionPoly(a);
//         double func_d = p1.DfunctionPoly(a);

//         // Prevent division by zero
//         if (fabs(func_d) < TOL)
//         {
//             std::cout << "Derivative too small, stopping iteration." << std::endl;
//             break;
//         }

//         // Newton-Raphson formula
//         double next_a = a - (func / func_d);

//         // Check for convergence
//         if (fabs(next_a - a) < TOL)
//         {
//             return next_a;
//         }

//         a = next_a;
//     }
//     return a;
// }



// Fixed Point Method
// double Root_Finding::Fixed_Point(double a)
// {
//     polynomial p1;
//     while (true)
//     {
//         double func_g = p1.function_g(a);

//         // Check for convergence
//         if (fabs(func_g - a) < TOL)
//         {
//             return func_g;
//         }
//         a = func_g;
//     }
//     return a;
// }

