﻿// Кумище_№6.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <Windows.h>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <numeric>
#include <functional>
#include <string>
#include <fstream>

#include "Language.h"
#include "Func.h"
#include "Tests.h"

using namespace std;

template<typename T>
void CheckInput(T& var);
void InputOption(int& var);

bool lessInNumOfLetters(Language l1, Language l2);
bool lessInNumOfCountries(Language l1, Language l2);
bool lessInName(Language l1, Language l2);
void findMoreThan(Language l1, string name);
void findMoreThan(Language l1, int num, int t);

int main()
{
	SetConsoleCP(1251); SetConsoleOutputCP(1251);

	int V = (int('K') + int('R')) % 8;
	cout << V << endl;
	cout << setw(40) << setfill('=') << ' ' << endl;


	int c = 0;
	string name = "";
	int num_of_letters = 0;
	bool left_to_right = true;
	int num_of_countries = 0;
	int t = 0;
	vector<Language> languages;
	Language one;
	ofstream out;
	ifstream in;
	string line;

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
		cout << "12 - тестирование" << endl;
		cout << "13 - выйти" << endl;
		cout << setw(40) << setfill('=') << ' ' << endl;

		cin >> c;
		CheckInput(c);

		switch (c)
		{
		case 1:
			cout << "Введите название: ";
			cin >> name;
			cout << "Введите направление (0 - справа налево, 1 - слева направо): ";
			cin >> left_to_right;
			CheckInput(left_to_right);
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
			cin >> num_of_countries;
			CheckInput(num_of_countries);
			while (num_of_countries < 0)
			{
				cout << "Некорректный ввод" << endl;
				cout << "Повторите ввод: ";
				cin >> num_of_countries;
				CheckInput(num_of_countries);
			}
			languages.push_back(Language(name, left_to_right, num_of_letters, num_of_countries));
			cout << "Язык записан" << endl;
			break;

		case 2:
			if (languages.size() == 0) break;
			languages.pop_back();
			cout << "Последний язык удален" << endl;
			break;

		case 3:
			if (languages.size() == 0) break;
			cout << "Вывод языков: " << endl;
			for (int i = 0; i < languages.size(); i++)
			{
				cout << i + 1 << "  " << setw(5) << setfill('-') << ' ' << endl;
				cout << languages[i];
				cout << setw(10) << setfill('-') << ' ' << endl;
			}
			break;

		case 4:
			if (languages.size() == 0) break;
			InputOption(t);
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
			if (languages.size() == 0) break;
			InputOption(t);
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
			if (languages.size() == 0) break;
			InputOption(t);
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
				[](int n, Language l2) 
				{ return n + (l2.get_num_of_letters() * l2.get_num_of_countries()); })
				<< endl;
			break;

		case 8:
			if (languages.size() == 0) break;
			InputOption(t);
			switch (t)
			{
			case 1:
				cout << "Введите пороговое значение имени: ";
				cin >> name;
				for_each(languages.begin(), languages.end(), [name](Language l)
					{findMoreThan(l, name); });
				break;
			case 2:
				cout << "Введите пороговое количество букв: ";
				cin >> num_of_letters;
				CheckInput(num_of_letters);
				while (num_of_letters < 1)
				{
					cout << "Некорректный ввод" << endl;
					cout << "Повторите ввод: ";
					cin >> num_of_letters;
					CheckInput(num_of_letters);
				}
				for_each(languages.begin(), languages.end(), [num_of_letters](Language l)
					{findMoreThan(l, num_of_letters, 0); });
				break;
			case 3:
				cout << "Введите пороговое количество стран: ";
				cin >> num_of_countries;
				CheckInput(num_of_countries);
				while (num_of_countries < 0)
				{
					cout << "Некорректный ввод" << endl;
					cout << "Повторите ввод: ";
					cin >> num_of_countries;
					CheckInput(num_of_countries);
				}
				for_each(languages.begin(), languages.end(), [num_of_countries](Language l)
					{findMoreThan(l, num_of_countries, 1); });
				break;
			}
			break;

		case 9:
			if (languages.size() == 0) break;
			InputOption(t);
			one = Language();
			switch (t)
			{
			case 1:
				cout << "Введите имя: ";
				cin >> name;
				if (find_if(languages.begin(), languages.end(), Func{ name }) != languages.end())
					one = *find_if(languages.begin(), languages.end(), Func{ name });
				break;
			case 2:
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
				if (find_if(languages.begin(), languages.end(),
					[num_of_letters](Language l)
					{ return l.get_num_of_letters() == num_of_letters; }) != languages.end())
					one = *find_if(languages.begin(), languages.end(),
						[num_of_letters](Language l)
						{ return l.get_num_of_letters() == num_of_letters; });
				break;
			case 3:
				cout << "Введите количество стран: ";
				cin >> num_of_countries;
				CheckInput(num_of_countries);
				while (num_of_countries < 0)
				{
					cout << "Некорректный ввод" << endl;
					cout << "Повторите ввод: ";
					cin >> num_of_countries;
					CheckInput(num_of_countries);
				}
				if (find_if(languages.begin(), languages.end(),
					[num_of_countries](Language l)
					{ return l.get_num_of_countries() == num_of_countries; }) != languages.end())
					one = *find_if(languages.begin(), languages.end(),
						[num_of_countries](Language l)
						{ return l.get_num_of_countries() == num_of_countries; });
				break;
			}
			if (one.get_name() != "null")
				cout << one;
			break;

		case 10:
			out.open("file.txt");
			if (out.is_open())
			{
				for (int i = 0; i < languages.size(); i++)
				{
					out << languages[i].get_name() << endl;
					out << languages[i].get_left_to_right() << endl;
					out << languages[i].get_num_of_letters() << endl;
					out << languages[i].get_num_of_countries() << endl;
				}
			}
			out.close();
			cout << "Данные записаны" << endl;
			break;

		case 11:
			in.open("file.txt");
			if (in.is_open())
			{
				languages.clear();
				while (in >> name >> left_to_right >> num_of_letters >> num_of_countries)
				{
					languages.push_back(Language(name, left_to_right, num_of_letters, num_of_countries));
				}
				cout << "Успешно" << endl;
			}
			in.close();
			break;

		case 12:
			Tests();

		case 13:
			return 0;
		
		default:
			break;
		}

		cout << setw(40) << setfill('=') << ' ' << endl;
		cout << endl;
	}
}

template<typename T>
void CheckInput(T& var)
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

void findMoreThan(Language l1, string name)
{
	if (l1.get_name() > name)
		cout << l1 << endl;
}

void findMoreThan(Language l1, int num, int t)
{
	if (t == 0)
	{
		if (l1.get_num_of_letters() > num)
			cout << l1 << endl;
	}
	else
	{
		if (l1.get_num_of_countries() > num)
			cout << l1 << endl;
	}
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
