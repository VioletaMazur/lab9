#include <iostream>
#include <cstring>

using namespace std;

// Функція, що імітує дії стандартної функції strrchr()
char* my_strrchr(const char* str, char ch) {
    char* lastOccurrence = nullptr;
    while (*str) {
        if (*str == ch) {
            lastOccurrence = const_cast<char*>(str);
        }
        str++;
    }
    return lastOccurrence;
}

// Функція, що імітує дії стандартної функції strcmp()
int my_strcmp(const char* str1, const char* str2) {
    // Порівнюємо символи у рядках
    while (*str1 && *str2) {
        if (*str1 != *str2)
            return *str1 - *str2;
        str1++;
        str2++;
    }
    return *str1 - *str2;
}

#include <iostream>

int main() {
    int choice;

    do {
        std::cout << "\nMenu:\n";
        std::cout << "1. Find last occurrence of character in string (strrchr)\n";
        std::cout << "2. Compare two strings (strcmp)\n";
        std::cout << "3. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
        case 1: {
            const int SIZE = 100;
            char str[SIZE], ch;

            std::cout << "Enter a string: ";
            std::cin.ignore();
            std::cin.getline(str, SIZE);

            std::cout << "Enter a character to search for: ";
            std::cin >> ch;

            char* result = my_strrchr(str, ch);

            if (result != nullptr) {
                std::cout << "Last occurrence of '" << ch << "' in the string: " << result << std::endl;
            }
            else {
                std::cout << "'" << ch << "' not found in the string." << std::endl;
            }
            break;
        }
        case 2: {
            char str1[100], str2[100];
            std::cout << "Enter first string: ";
            std::cin >> str1;
            std::cout << "Enter second string: ";
            std::cin >> str2;
            int result = my_strcmp(str1, str2);
            if (result < 0)
                std::cout << "First string is less than second string." << std::endl;
            else if (result > 0)
                std::cout << "First string is greater than second string." << std::endl;
            else
                std::cout << "Strings are equal." << std::endl;
            break;
        }
        case 3:
            std::cout << "Exiting program." << std::endl;
            break;
        default:
            std::cout << "Invalid choice. Please try again." << std::endl;
        }
    } while (choice != 3);

    return 0;
}

