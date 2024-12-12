#include <stdio.h>
#include <math.h>

#define EPSILON 1e-6 
#define MAX_ITER 1000
M_PI = 3.14;

double f(double x) {
    return sqrt(x) - 2 * cos((M_PI / 2) * x);
}

double f_derivative(double x) {
    return 1 / (2 * sqrt(x)) + M_PI * sin((M_PI / 2) * x);
}

double bisection(double a, double b) {
    double c;
    int iter = 0;

    while ((b - a) / 2 > EPSILON && iter < MAX_ITER) {
        c = (a + b) / 2;
        if (f(c) == 0.0)
            break;
        else if (f(a) * f(c) < 0)
            b = c;
        else
            a = c;
        iter++;
    }
    return c;
}

double chord(double a, double b) {
    double c;
    int iter = 0;

    while (fabs(b - a) > EPSILON && iter < MAX_ITER) {
        c = b - (f(b) * (b - a)) / (f(b) - f(a));
        a = b;
        b = c;
        iter++;
    }
    return c;
}

double tangent(double x0) {
    double x1;
    int iter = 0;

    do {
        x1 = x0 - f(x0) / f_derivative(x0);
        if (fabs(x1 - x0) < EPSILON)
            break;
        x0 = x1;
        iter++;
    } while (iter < MAX_ITER);

    return x1;
}

int main() {
    double a = 0.1, b = 2.0; 

    
    double root_bisection = bisection(a, b);
    printf("Root (Bisection): %.6f\n", root_bisection);


    double root_chord = chord(a, b);
    printf("Root (Chord): %.6f\n", root_chord);

 
    double root_tangent = tangent((a + b) / 2);
    printf("Root (Tangent): %.6f\n", root_tangent);

    return 0;
}