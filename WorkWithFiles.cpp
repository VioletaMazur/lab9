#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include <windows.h>
#include "process_file.h"

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);


    while (true) {
        std::cout << "\n\nОбробка текстових файлів\n";
        std::cout << "1. Ввести ім'я вхідного файлу\n";
        std::cout << "2. Завершити програму\n";
        std::cout << "Виберіть пункт меню: ";

        int choice;
        std::cin >> choice;

        if (choice == 1) {
            char input_filename[100];
            std::cout << "Введіть ім'я вхідного файлу: ";
            std::cin >> input_filename;

            std::ifstream input_file(input_filename, std::ios::in);
            if (!input_file.is_open()) {
                std::cerr << "Файл не знайдено: " << input_filename << std::endl;
                continue;
            }

            char* output_filename = nullptr;

            while (true) {
                std::cout << "\n\nОбробка файлу: " << input_filename << "\n";
                std::cout << "1. Вивести вхідний файл\n";
                std::cout << "2. Обробити файл\n";
                std::cout << "3. Вивести кількість цифр у вхідному файлі\n";
                std::cout << "4. Вивести вихідний файл\n";
                std::cout << "5. Завершити роботу з файлом\n";
                std::cout << "Виберіть пункт меню: ";

                int file_choice;
                std::cin >> file_choice;

                if (file_choice == 1) {
                    print_file_content(input_filename);
                }
                else if (file_choice == 2) {
                    if (output_filename) {
                        delete[] output_filename;
                    }
                    output_filename = generate_output_filename(input_filename);
                    if (!output_filename) {
                        std::cerr << "Не вдалося отримати ім'я вихідного файлу.\n";
                        continue;
                    }

                    process_file(input_filename, output_filename);
                }
                else if (file_choice == 3) {
                    std::cout << "Кількість цифр у вхідному файлі: " << count_digits(input_filename) << std::endl;
                }
                else if (file_choice == 4) {
                    if (!output_filename) {
                        std::cerr << "Спочатку обробіть файл.\n";
                        continue;
                    }
                    print_file_content(output_filename);
                }
                else if (file_choice == 5) {
                    break;
                }
                else {
                    std::cerr << "Неправильний вибір пункту меню!\n";
                }
            }

            if (output_filename) {
                delete[] output_filename;
            }
        }
        else if (choice == 2) {
            std::cout << "Програма завершена.\n";
            break;
        }
        else {
            std::cerr << "Неправильний вибір пункту меню!\n";
        }
    }

    return 0;
}
