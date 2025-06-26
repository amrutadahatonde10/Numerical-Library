#include <iostream>
class cmplx
{
public:
  double real;
  double img;

public:
  cmplx();            // constructor
  void display();     // fun to print the complex no.
  cmplx add(cmplx y); // fun to add two complex no
  cmplx sub(cmplx y); // fun to subtract two complex no
};