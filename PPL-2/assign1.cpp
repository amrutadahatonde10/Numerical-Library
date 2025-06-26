#include <iostream>
using namespace std;

float calculate(float c)
{
     return (1.8 * c) + 32;
}

int main() {
    float celsius, fahrenheit;

    cout << "Enter the temperature in Celsius: ";
    cin >> celsius;

    fahrenheit = calculate(celsius);

    cout << "Temperature in Fahrenheit: " << fahrenheit << endl;

    return 0;
}
