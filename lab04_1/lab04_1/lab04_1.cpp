#include <iostream>
#include <iomanip>
double sum_divisors(int n) {
    if (n == 0) return 1.0;
    int sum = 0;
    int abs_n = abs(n);
    for (int i = 1; i <= abs_n; ++i) {
        if (abs_n % i == 0) sum += i;
    }
    return (double)sum;
}

int main() {
    const int ROWS = 3;
    const int COLS = 3;
    int matrix[ROWS][COLS] = {
        {6, 10, 15},
        {3, 8, 12},
        {7, 4, 9}
    };
    double result[ROWS][COLS];

    std::cout << "Original Matrix:\n";
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            std::cout << matrix[i][j] << "\t";
            result[i][j] = (double)matrix[i][j] / sum_divisors(matrix[i][j]);
        }
        std::cout << "\n";
    }

    std::cout << "\nProcessed Matrix (element / sum of divisors):\n";
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            std::cout << std::fixed << std::setprecision(3) << result[i][j] << "\t";
        }
        std::cout << "\n";
    }

    return 0;
}