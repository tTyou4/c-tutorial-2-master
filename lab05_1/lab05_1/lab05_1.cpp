#include <iostream>
#include <string>

std::string encryptCaesar(std::string text, int key) {
    std::string result = "";

    key = key % 26;

    for (char& c : text) {
        if (isupper(c)) {
            result += char(int(c + key - 65) % 26 + 65);
        }
        else if (islower(c)) {
            result += char(int(c + key - 97) % 26 + 97);
        }
        else {
            result += c;
        }
    }
    return result;
}

int main() {
    std::string text;
    int key;

    std::cout << "Enter the string to encrypt: ";
    std::getline(std::cin, text);
    std::cout << "Enter the key: ";
    std::cin >> key;

    std::string encrypted = encryptCaesar(text, key);
    std::cout << "Encrypted string: " << encrypted << std::endl;

    return 0;
}