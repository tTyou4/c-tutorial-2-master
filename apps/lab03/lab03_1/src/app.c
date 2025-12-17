#include <stdio.h>
#include <math.h>
#include <float.h>

int main() {
    double a = -5.0, b = 5.0, h = 0.1, x;
    double min_y = DBL_MAX, max_y = -DBL_MAX;

    printf("--- Part 1: Function y = f(x) ---\n");
    printf("x\t\ty\n");
    printf("------------------------\n");

    for (x = a; x <= b + h / 2; x += h) {
        double y;
        if (x <= 1.0) {
            y = sin(sqrt(1.0 - x));
        }
        else if (x > 1.0 && x < 3.0) {
            y = cos(x * x);
        }
        else {
            y = 7.0 - x;
        }

        if (y < min_y) min_y = y;
        if (y > max_y) max_y = y;

        printf("%.3f\t%.3f\n", x, y);
    }

    printf("------------------------\n");
    printf("Min y: %.3f\tMax y: %.3f\n\n", min_y, max_y);

    return 0;
}