#include <stdio.h>
#include <math.h>
#include <float.h>

int main() {
    double ax = -3.0, bx = 3.0, hx = 0.25;
    double ay = 1.0, by = 2.0, hy = 0.15;
    double x, y, z;
    double min_z = DBL_MAX, max_z = -DBL_MAX;

    printf("--- Part 2: Function z = f(x, y) ---\n");
    printf("y\\x\t");

    for (x = ax; x <= bx + hx / 2; x += hx) {
        printf("%.2f\t", x);
    }
    printf("\n");

    for (y = ay; y <= by + hy / 2; y += hy) {
        printf("%.2f\t", y);
        for (x = ax; x <= bx + hx / 2; x += hx) {
            if ((x * (y + 1.0) >= 0) && (fabs(x - y) > 1e-7)) {
                z = sqrt(x * (y + 1.0)) / (x - y);
                printf("%.3f\t", z);

                if (z < min_z) min_z = z;
                if (z > max_z) max_z = z;
            }
            else {
                printf("NaN\t");
            }
        }
        printf("\n");
    }

    printf("------------------------\n");
    if (min_z != DBL_MAX)
        printf("Min z: %.3f\tMax z: %.3f\n", min_z, max_z);
    else
        printf("Valid values for z not found in this range.\n");

    return 0;
}