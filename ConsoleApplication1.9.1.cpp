#include <iostream> 

#include <cstring> 

#include <windows.h> 

// Функція для порівняння двох масивів символів 

bool areEqual(char arr1[], char arr2[], int n) {

    for (int i = 0; i < n; ++i) {

        if (arr1[i] != arr2[i]) {

            return false;

        }

    }

    return true;

}



int main() {

    SetConsoleCP(1251);

    SetConsoleOutputCP(1251);

    const int MAX_WORDS = 100;

    char words[MAX_WORDS][20];

    int n = 0; // Лічильник кількості введених слів 



    std::cout << "Введіть слова (введіть '+', коли закінчите):\n";

    while (true) {

        std::cin >> words[n];

        if (strcmp(words[n], "+") == 0) {

            break; // Виходимо з циклу, якщо введено 'готово' 

        }

        ++n;

        if (n >= MAX_WORDS) {

            std::cout << "Досягнуто максимальної кількості слів. Завершення введення.\n";

            break;

        }

    }



    // Перебір кожного слова в масиві 

    for (int i = 0; i < n; ++i) {

        // Перевірка чи слово вже було пораховане 

        bool isCounted = false;

        for (int j = 0; j < i; ++j) {

            if (areEqual(words[i], words[j], 20)) {

                isCounted = true;

                break;

            }

        }

        if (!isCounted) {

            // Лічильник кількості повторень поточного слова 

            int wordCount = 1;

            // Перебір інших слів, щоб знайти входження поточного слова 

            for (int k = i + 1; k < n; ++k) {

                if (areEqual(words[i], words[k], 20)) {

                    ++wordCount;

                }

            }

            // Вивід слова та кількості його повторень 

            std::cout << "Слово: " << words[i] << " Кількість: " << wordCount << std::endl;

        }

    }

    system("pause");

    return 0;

}

