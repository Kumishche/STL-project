#include "Tests.h"
using namespace std;

void Tests()
{
	string name = "";
	int num_of_letters = 0;
	bool left_to_right = true;
	int num_of_countries = 0;
	vector<Language> languages(4);
	ofstream out;
	ifstream in;
	string line;
	languages[0] = Language("ru", true, 33, 4);
	languages[2] = Language("he", false, 22, 1);
	languages[1] = Language("en", true, 26, 57);
	languages[3] = Language("la", true, 23, 0);

	for (int i = 0; i < 4; i++)
	{
		cout << i + 1 << endl;
		cout << languages[i];
		cout << "=================" << endl;
	}

	{
		cout << "Сортировка по имени: " << endl;
		sort(languages.begin(), languages.end(), lessInName_test);
		for (int i = 0; i < 4; i++)
		{
			cout << i + 1 << endl;
			cout << languages[i];
			cout << "=================" << endl;
		}
		cout << endl;

		cout << "Сортировка по количеству букв: " << endl;
		sort(languages.begin(), languages.end(), lessInNumOfLetters_test);
		for (int i = 0; i < 4; i++)
		{
			cout << i + 1 << endl;
			cout << languages[i];
			cout << "=================" << endl;
		}
		cout << "=================" << endl;
		cout << endl;

		cout << "Сортировка по количеству стран: " << endl;
		sort(languages.begin(), languages.end(), lessInNumOfCountries_test);
		for (int i = 0; i < 4; i++)
		{
			cout << i + 1 << endl;
			cout << languages[i];
			cout << "=================" << endl;
		}
		cout << "=================" << endl;
		cout << endl << endl;
	}

	{
		cout << "Минимальный по имени: " << endl;
		cout << *min_element(languages.begin(), languages.end(), lessInName_test) << endl;
		cout << "=================" << endl;
		cout << endl;

		cout << "Минимальный по количеству букв: " << endl;
		cout << *min_element(languages.begin(), languages.end(), lessInNumOfLetters_test) << endl;
		cout << "=================" << endl;
		cout << endl;

		cout << "Минимальный по количеству стран: " << endl;
		cout << *min_element(languages.begin(), languages.end(), lessInNumOfCountries_test) << endl;
		cout << "=================" << endl;
		cout << endl << endl;
	}

	{
		cout << "Максимальный по имени: " << endl;
		cout << *max_element(languages.begin(), languages.end(), lessInName_test) << endl;
		cout << "=================" << endl;
		cout << endl;

		cout << "Максимальный по количеству букв: " << endl;
		cout << *max_element(languages.begin(), languages.end(), lessInNumOfLetters_test) << endl;
		cout << "=================" << endl;
		cout << endl;

		cout << "Максимальный по количеству стран: " << endl;
		cout << *max_element(languages.begin(), languages.end(), lessInNumOfCountries_test) << endl;
		cout << "=================" << endl;
		cout << endl << endl;
	}

	{
		cout << "Агрегированное значение: " << endl;
		cout << accumulate(languages.begin(), languages.end(), 0,
			[](int n, Language l2)
			{ return n + (l2.get_num_of_letters() * l2.get_num_of_countries()); })
			<< endl;
		cout << "=================" << endl;
		cout << endl << endl;
	}

	{
		cout << "Пороговое значение имени \"id\": " << endl;
		for_each(languages.begin(), languages.end(), [](Language l)
			{findMoreThan_test(l, "id"); });
		cout << "=================" << endl;

		cout << "Пороговое значение количества букв 24: " << endl;
		for_each(languages.begin(), languages.end(), [](Language l)
			{findMoreThan_test(l, 24, 0); });
		cout << "=================" << endl;

		cout << "Пороговое значение количества стран 1: " << endl;
		for_each(languages.begin(), languages.end(), [](Language l)
			{findMoreThan_test(l, 1, 1); });
		cout << "=================" << endl;
		cout << endl << endl;
	}

	{
		cout << "Поиск по имени \"ru\": " << endl;
		if (find_if(languages.begin(), languages.end(), Func{ "ru"}) != languages.end())
			cout << *find_if(languages.begin(), languages.end(), Func{ "ru"});
		cout << "=================" << endl;

		cout << "Поиск по количеству букв 22: " << endl;
		if (find_if(languages.begin(), languages.end(),
			[](Language l)
			{ return l.get_num_of_letters() == 22; }) != languages.end())
			cout << *find_if(languages.begin(), languages.end(),
				[](Language l)
				{ return l.get_num_of_letters() == 22; });
		cout << "=================" << endl;

		cout << "Поиск по количеству стран 0: " << endl;
		if (find_if(languages.begin(), languages.end(),
			[](Language l)
			{ return l.get_num_of_countries() == 0; }) != languages.end())
			cout << *find_if(languages.begin(), languages.end(),
				[](Language l)
				{ return l.get_num_of_countries() == 0; });
		cout << "=================" << endl;
		cout << endl << endl;
	}

	{
		cout << "Запись в файл: " << endl;
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
	}

	{
		cout << "Чтение из файла: " << endl;
		in.open("file.txt");
		if (in.is_open())
		{
			languages.clear();
			while (in >> name >> left_to_right >> num_of_letters >> num_of_countries)
			{
				languages.push_back(Language(name, left_to_right, num_of_letters, num_of_countries));
			}
			for (int i = 0; i < 4; i++)
			{
				cout << i + 1 << endl;
				cout << languages[i];
				cout << "=================" << endl;
			}
		}
	}

}

bool lessInNumOfLetters_test(Language l1, Language l2)
{
	return l1.get_num_of_letters() < l2.get_num_of_letters();
}

bool lessInNumOfCountries_test(Language l1, Language l2)
{
	return l1.get_num_of_countries() < l2.get_num_of_countries();
}

bool lessInName_test(Language l1, Language l2)
{
	return l1.get_name() < l2.get_name();
}

void findMoreThan_test(Language l1, string name)
{
	if (l1.get_name() > name)
		cout << l1 << endl;
}

void findMoreThan_test(Language l1, int num, int t)
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