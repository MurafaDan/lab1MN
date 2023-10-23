#include <iostream>
#include <cmath>

using namespace std;

double function(double x)
{

    return 1.5 * pow(x*x , 1.0 / 5.0) - 5 * atan(x) - pow(x, 2) + 5;
}
double derivative(double x)
{
    // Derivative of the given function
    return -3 / (5 * pow(x*x , 2.0 / 5.0)) - 5 / (pow(x, 2) + 1) - 2 * x;
}
double g_function(double x)
{
    return sqrt(1.5 * pow(x*x, 1.0 / 5.0) - 5 * atan(x) + 5);
}

double bisection(double a, double b, double error)
{
    int i = 0;
    if (function(a) * function(b) >= 0)
    {
        cout << "Bisection method cannot be applied in this range." << endl;
        return 0.0;
    }

    double c;

    while (abs(b - a) >= error)
    {
        i++;
        // Find middle point
        c = (a + b) / 2;

        // Check if middle point is root
        if (function(c) == 0.0)
            break;

            // Decide the side to repeat the steps
        else if (function(c) * function(a) < 0)
            b = c;
        else
            a = c;
    }
    cout << " Numarul de iteratii " << i << endl;
    return c;
}

double newton(double x0, double error)
{
    int i = 0;
    double x = x0;
    double x1;

    do
    {
        i++;
        x1 = x;
        x = x - function(x) / derivative(x);

    } while (abs(x - x1) >= error);
    cout << " Numarul de iteratii " << i << endl;

    return x;
}

double secant(double x0, double x1, double error)
{
    int i = 0;
    double x2;

    do
    {
        i++;
        x2 = x1 - (function(x1) * (x1 - x0)) / (function(x1) - function(x0));
        x0 = x1;
        x1 = x2;

    } while (abs(function(x2)) >= error);
    cout << " Numarul de iteratii " << i << endl;

    return x2;
}

double successiveApproximation(double x, double error)
{
    int i = 0;
    do
    {
        i++;
        x = g_function(x);

    } while (abs(function(x)) > error);
    cout << " Numarul de iteratii " << i << endl;
    return x;
}

int main()
{
    double a = -5.0, b = 5.0;
    double const error = pow(10, -6);

    // Bisection Method
    double rootBisection = bisection(a, b, error);
    cout << "Bisection Method Result: " << rootBisection << endl;

    // Newton's Method
    double rootNewton1 = newton(-1.5,  error);
    double rootNewton2 = newton(1, error);
    cout << "Newton's Method Result: X1 = " << rootNewton1 << ", X2 = " << rootNewton2 << endl;

    // Secant Method
    double rootSecant1 = secant(-3.5, -4.0, error);
    double rootSecant2 = secant(1, 2, error);
    cout << "Secant Method Result: X1 = " << rootSecant1 << ", X2 = " << rootSecant2 << endl;

    // Successive Approximation Method
    double rootSuccessive1 = successiveApproximation(-3.5, error);
    double rootSuccessive2 = successiveApproximation(1, error);
    cout << "Successive Approximation Method Result: X1 = " << rootSuccessive1 << ", X2 = " << rootSuccessive2 << endl;

    return 0;
}