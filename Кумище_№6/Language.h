#pragma once
#include <iostream>

class Language
{
private:
	std::string name;
	int num_of_letters;
	int num_of_countries;
	std::string* countries;

public:
	Language();
	Language(std::string n, int num, std::string* c, int size);
	Language(const Language& other);
	~Language();

	int get_num_of_letters();
	int get_num_of_countries();
	std::string get_name();

	Language operator= (const Language& other);
	friend std::ostream& operator<<(std::ostream& os, Language& language);
};