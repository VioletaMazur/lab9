#include <iostream>
#include <string>
#include <vector>
#include "file_processing.h"
#include <windows.h>

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    std::string inputFileName, outputFileName;
    std::vector<int> lineLengths;

    // Запит ім'я вхідного файлу
    std::cout << "Введіть назву вхідного файлу: ";
    std::cin >> inputFileName;

    // Копіювання вмісту вхідного файлу у вихідний файл та підрахунок кількості рядків і символів
    outputFileName = inputFileName.substr(0, 3) + "_out.dat";
    copyFile(inputFileName, outputFileName, lineLengths);

    // Виведення повідомлення про успішне завершення роботи
    std::cout << "Файл успішно оброблено. Вивід записаний " << outputFileName << std::endl;

    // Запит користувача на виведення тексту вхідного файлу на екран
    char choice;
    std::cout << "Ви бажаєте відобразити вміст вхідного файлу? (y/n): ";
    std::cin >> choice;
    if (choice == 'y' || choice == 'Y') {
        std::ifstream inputFile(inputFileName);
        std::string line;
        while (std::getline(inputFile, line)) {
            std::cout << line << std::endl;
        }
        inputFile.close();
    }

    // Запит користувача на виведення тексту вихідного файлу на екран
    std::cout << "Ви хочете відобразити вміст вихідного файлу? (y/n): ";
    std::cin >> choice;
    if (choice == 'y' || choice == 'Y') {
        std::ifstream outputFile(outputFileName);
        std::string line;
        while (std::getline(outputFile, line)) {
            std::cout << line << std::endl;
        }
        outputFile.close();
    }

    return 0;
}
