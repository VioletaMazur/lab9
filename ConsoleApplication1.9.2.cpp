#include <iostream>
#include <cstring>
#include <windows.h>
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
// Функція, що імітує дії стандартної функції strncmp()
int my_strncmp(const char* str1, const char* str2, int n) {
	int cn = 0;
	while (*str1 && *str2 && cn < n) {
		if (*str1 != *str2) {
			return *str1 - *str2;
		}
		str1++;
		str2++;
		cn++;
	}

	// Якщо досягли межі порівняння n або обидва рядки закінчилися одночасно
	if (cn == n) {
		return 0;
	}

	// Якщо один з рядків закінчився раніше
	if (*str1) {
		return 1;
	}
	else if (*str2) {
		return -1;
	}
	else {
		return 0;
	}
}

#include <iostream>
int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int choice;
	do {
		cout << "\nМеню:\n";
		cout << "1. Знайти останнє входження символу у рядку (strrchr)\n";
		cout << "2. Порівняти два рядки (strncmp)\n";
		cout << "3. Вихід\n";
		cout << "Введіть свій вибір: ";
		cin >> choice;
		switch (choice) {
		case 1: {
			const int SIZE = 100;
			char str[SIZE], ch;
			cout << "Введіть рядок: ";
			cin.ignore();
			cin.getline(str, SIZE);
			cout << "Введіть символ, який потрібно знайти: ";
			cin >> ch;
			char* result = my_strrchr(str, ch);
			cout << "\nРезультат роботи функції my_strrchr(): \n";
			if (result != nullptr) {
				cout << "Позиція останнього входження символу '" << ch << "' у рядку: " << result - str << endl;
			}
			else {
				cout << "'" << ch << "' не знайдено у рядку." << endl;
			}

			char* c_result = strrchr(str, ch);
			cout << "\nРезультат роботи функції strrchr(): \n";
			if (c_result != nullptr) {
				cout << "Позиція останнього входження символу '" << ch << "' у рядку: " << c_result - str << endl;
			}
			else {
				cout << "'" << ch << "' не знайдено у рядку." << endl;
			}

			cout << endl;

			if (result == c_result) {
				cout << "Функції strrchr() і my_strrchr() повернули однакові значення." << endl;
			}
			else {
				cout << "Функції strrchr() і my_strrchr() повернули різні значення." << endl;
			}




			break;
		}
		case 2: {
			char str1[100], str2[100];
			int n;
			cout << "Введіть перший рядок: ";
			cin.ignore();
			cin.getline(str1, 100);
			cout << "Введіть другий рядок: ";
			cin.getline(str2, 100);
			cout << "Введіть кількість символів, які потрібно порівняти: ";
			cin >> n;

			int result = my_strncmp(str1, str2, n);
			cout << "\nРезультат роботи функції my_strncmp(): \n";
			if (result < 0)
				cout << "Перший рядок менший за другий." << endl;
			else if (result > 0)
				cout << "Перший рядок більший за другий." << endl;
			else
				cout << "Рядки рівні." << endl;

			int c_result = strncmp(str1, str2, n);
			cout << "\nРезультат роботи функції strncmp(): \n";
			if (c_result < 0)
				cout << "Перший рядок менший за другий." << endl;
			else if (c_result > 0)
				cout << "Перший рядок більший за другий." << endl;
			else
				cout << "Рядки рівні." << endl;

			cout << endl;

			if (result == c_result) {
				cout << "Функції strncmp() і my_strncmp() повернули однакові значення." << endl;
			}
			else {
				cout << "Функції strncmp() і my_strncmp() повернули різні значення." << endl;
			}

			break;
		}
		case 3:
			cout << "Завершення програми." << endl;
			break;
		default:
			cout << "Некоректний вибір. Будь ласка, спробуйте ще раз." << endl;
		}
	} while (choice != 3);
	system("pause");
	return 0;
}
