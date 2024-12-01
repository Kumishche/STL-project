// Кумище_№6.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <Windows.h>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <numeric>

#include "Language.h"

using namespace std;


void CheckInput(int& var);
void InputOption(int& var);

bool lessInNumOfLetters(Language l1, Language l2);
bool lessInNumOfCountries(Language l1, Language l2);
bool lessInName(Language l1, Language l2);


int main()
{
	SetConsoleCP(1251); SetConsoleOutputCP(1251);

	int V = (int('K') + int('R')) % 8;
	cout << V << endl;
	cout << setw(40) << setfill('=') << ' ' << endl;


	int c = 0;
	string name = "";
	int num_of_letters = 0;
	string* countries = nullptr;
	int size = 0;
	int id = 0;
	int t = 0;
	int num = 0;
	vector<Language> languages;
	Language one;

	while (true)
	{
		cout << "Выберите действие: " << endl;
		cout << "1 - добавить язык" << endl;
		cout << "2 - удалить язык" << endl;
		cout << "3 - вывести языки" << endl;
		cout << setw(20) << setfill('-') << ' ' << endl;
		cout << "4 - сортировка" << endl;
		cout << "5 - поиск максимального" << endl;	
		cout << "6 - поиск минимального" << endl;
		cout << "7 - агрегированное значение" << endl;
		cout << "8 - отбор элементов" << endl;
		cout << "9 - поиск элемента" << endl;
		cout << "10 - запись в файл" << endl;
		cout << "11 - чтение из файла" << endl;
		cout << setw(20) << setfill('-') << ' ' << endl;
		cout << "12 - выйти" << endl;
		cout << setw(40) << setfill('=') << ' ' << endl;

		cin >> c;
		CheckInput(c);

		switch (c)
		{
		case 1:
			cout << "Введите название: ";
			cin >> name;
			cout << "Введите количество букв: ";
			cin >> num_of_letters;
			CheckInput(num_of_letters);
			while (num_of_letters < 1)
			{
				cout << "Некорректный ввод" << endl;
				cout << "Повторите ввод: ";
				cin >> num_of_letters;
				CheckInput(num_of_letters);
			}
			cout << "Введите количество стран: ";
			cin >> size;
			CheckInput(size);
			while (size < 0)
			{
				cout << "Некорректный ввод" << endl;
				cout << "Повторите ввод: ";
				cin >> size;
				CheckInput(size);
			}
			delete[] countries;
			countries = new string[size];
			cout << "Введите страны: " << endl;
			for (int i = 0; i < size; i++)
			{
				cin >> countries[i];
			}
			languages.push_back(Language(name, num_of_letters, countries, size));
			cout << "Язык записан" << endl;
			break;

		case 2:
			if (languages.size() == 0)
			{
				cout << "Нечего удалять..." << endl;
				break;
			}
			languages.pop_back();
			cout << "Последний язык удален" << endl;
			break;

		case 3:
			cout << "Вывод языков: " << endl;
			if (languages.size() == 0) break;
			for (int i = 0; i < languages.size(); i++)
			{
				cout << i + 1 << "  " << setw(5) << setfill('-') << ' ' << endl;
				cout << languages[i] << endl;
				cout << setw(10) << setfill('-') << ' ' << endl;
			}
			break;

		case 4:
			InputOption(t);
			if (languages.size() == 0) break;
			switch (t)
			{
			case 1:
				sort(languages.begin(), languages.end(), lessInName);
				break;
			case 2:
				sort(languages.begin(), languages.end(), lessInNumOfLetters);
				break;
			case 3:
				sort(languages.begin(), languages.end(), lessInNumOfCountries);
				break;
			}
			cout << "Языки отсортированы" << endl;
			break;

		case 5:
			InputOption(t);
			if (languages.size() == 0) break;
			switch (t)
			{
			case 1:
				one = *max_element(languages.begin(), languages.end(), lessInName);
				break;
			case 2:
				one = *max_element(languages.begin(), languages.end(), lessInNumOfLetters);
				break;
			case 3:
				one = *max_element(languages.begin(), languages.end(), lessInNumOfCountries);
				break;
			}
			cout << one;
			break;

		case 6:
			InputOption(t);
			if (languages.size() == 0) break;
			switch (t)
			{
			case 1:
				one = *min_element(languages.begin(), languages.end(), lessInName);
				break;
			case 2:
				one = *min_element(languages.begin(), languages.end(), lessInNumOfLetters);
				break;
			case 3:
				one = *min_element(languages.begin(), languages.end(), lessInNumOfCountries);
				break;
			}
			cout << one;
			break;

		case 7:
			if (languages.size() == 0) break;
			cout << "Агрегированное значение: ";
			cout << accumulate(languages.begin(), languages.end(), 0,
				[](int n, Language l2) { return n + l2.get_num_of_letters(); }) << endl;
			break;

		case 8:
			break;

		case 9:
			break;

		case 10:
			break;

		case 11:
			break;

		case 12:
			return 0;
		
		default:
			break;
		}

		cout << setw(40) << setfill('=') << ' ' << endl;
		cout << endl;
	}
}

void CheckInput(int& var)
{
	while (cin.fail() || cin.get() != '\n')
	{
		cin.clear(); cin.ignore(256, '\n');
		cout << "Некорректный ввод" << endl;
		cout << "Повторите ввод: ";
		cin >> var;
	}
}

void InputOption(int& var)
{
	cout << "Выберите характеристику:" << endl;
	cout << "1 - имя, 2 - количество букв, 3 - количество стран" << endl;
	cin >> var;
	CheckInput(var);
	while (var < 1 || var > 3)
	{
		cout << "Некорректный ввод" << endl;
		cout << "Повторите ввод: ";
		cin >> var;
		CheckInput(var);
	}
}

bool lessInNumOfLetters(Language l1, Language l2)
{
	return l1.get_num_of_letters() < l2.get_num_of_letters();
}

bool lessInNumOfCountries(Language l1, Language l2)
{
	return l1.get_num_of_countries() < l2.get_num_of_countries();

}

bool lessInName(Language l1, Language l2)
{
	return l1.get_name() < l2.get_name();
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
