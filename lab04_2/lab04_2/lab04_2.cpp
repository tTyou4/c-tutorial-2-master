#include <iostream>
#include <vector>
#include <cmath>

int main() {
    std::vector<int> arr = { 102, 33, 456, 707, 89, 12 };
    int digit_count[10] = { 0 }; // Масив для лічильників цифр 0-9

    for (int num : arr) {
        int temp = std::abs(num);
        if (temp == 0) {
            digit_count[0]++;
            continue;
        }
        while (temp > 0) {
            int digit = temp % 10;
            digit_count[digit]++;
            temp /= 10;
        }
    }

    std::cout << "Digit statistics in the array:\n";
    for (int i = 0; i < 10; ++i) {
        if (digit_count[i] > 0) {
            std::cout << "Digit " << i << " occurs " << digit_count[i] << " times\n";
        }
    }

    return 0;
}