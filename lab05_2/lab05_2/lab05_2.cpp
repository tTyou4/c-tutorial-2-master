#include <iostream>
#include <string>

void bruteForceCaesar(std::string ciphertext) {
    std::cout << "Decryption attempt:" << std::endl;

    for (int key = 1; key < 26; ++key) {
        std::string decrypted = "";
        for (char c : ciphertext) {
            if (isupper(c)) {
                decrypted += char((c - 'A' - key + 26) % 26 + 'A');
            }
            else if (islower(c)) {
                decrypted += char((c - 'a' - key + 26) % 26 + 'a');
            }
            else {
                decrypted += c;
            }
        }
        std::cout << "Key " << key << ": " << decrypted << std::endl;
    }
}

int main() {
    std::string ciphertext;

    std::cout << "Enter the encrypted string: ";
    std::getline(std::cin, ciphertext);

    bruteForceCaesar(ciphertext);

    return 0;
}