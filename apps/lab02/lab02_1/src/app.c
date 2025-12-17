#include "app.h"

/*
  Віріант: 9
 
  f(x) = 1/4 * ln((x+1)/(1-x)) + 1/2 * arctgx
  S = Sum_{n=0}^{\infty} x^(4n+1) / (4n+1)
 
 */

#define A_START 0.0
#define B_END   1.0
#define K_POINTS 21
#define N_MAX    5
#define EPSILON 0.0001

double calculate_f(double x) {
    if (x >= 1.0) {
        return NAN;
    }
    double arg_ln = (x + 1.0) / (1.0 - x);

    return 0.25 * log(arg_ln) + 0.5 * atan(x);
}

double calculate_S_n(double x, int max_n) {
    double sum = 0.0;
    for (int n = 0; n <= max_n; ++n) {
        double term = pow(x, 4 * n + 1) / (4 * n + 1);
        sum += term;
    }
    return sum;
}

double calculate_S_epsilon(double x, double epsilon) {
    double sum = 0.0;
    double term;
    int n = 0;

    if (fabs(x) < 1e-12) return 0.0;

    term = x;
    sum += term;
    n++;

    do {
        term = pow(x, 4 * n + 1) / (4 * n + 1);
        sum += term;
        n++;
    } while (fabs(term) > epsilon);

    return sum;
}

int main()
{
    double h = (B_END - A_START) / (K_POINTS - 1);
    double x;
    int i;

    printf("================================================================\n");
    printf("| X      |    f(x)    |   S (N=%d)  | S (%.4f) |       n      |\n", N_MAX, EPSILON);
    printf("================================================================\n");

    for (i = 0; i < K_POINTS; ++i) {
        x = A_START + i * h;

        if (x >= 1.0) x = 0.9999999;

        double f_x = calculate_f(x);
        double s_n = calculate_S_n(x, N_MAX);
        double s_epsilon = 0.0;
        int n_actual = 0;

        if (fabs(x) > 1e-12) {
            double current_sum = 0.0;
            double term;
            n_actual = 0;

            term = pow(x, 4 * n_actual + 1) / (4 * n_actual + 1);
            current_sum += term;
            n_actual++;

            while (fabs(term) > EPSILON && n_actual < 1000) {
                term = pow(x, 4 * n_actual + 1) / (4 * n_actual + 1);
                current_sum += term;
                n_actual++;
            }
            s_epsilon = current_sum;
        }


        if (isnan(f_x)) {
            printf("| %.4f | Розходиться  | %.8f | %.8f | %12d |\n", x, s_n, s_epsilon, n_actual);
        }
        else {
            printf("| %.4f | %.8f | %.8f | %.8f | %12d |\n", x, f_x, s_n, s_epsilon, n_actual);
        }
    }

    printf("================================================================\n");

    return 0;
}