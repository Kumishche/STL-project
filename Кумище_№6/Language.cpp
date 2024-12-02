#include "Language.h"


Language::Language()
{
	name = "null";
	left_to_right = true;
	num_of_letters = 0;
	num_of_countries = 0;
	countries = nullptr;
}


Language::Language(std::string n, bool l, int num, std::string* c, int size)
{
	name = n;
	left_to_right = l;
	num_of_letters = num;
	num_of_countries = size;
	countries = new std::string[size];
	for (int i = 0; i < size; i++)
	{
		countries[i] = c[i];
	}
}


Language::Language(const Language& other)
{
	name = other.name;
	left_to_right = other.left_to_right;
	num_of_letters = other.num_of_letters;
	num_of_countries = other.num_of_countries;
	countries = new std::string[num_of_countries];
	for (int i = 0; i < num_of_countries; i++)
	{
		countries[i] = other.countries[i];
	}
}


Language::~Language()
{
	delete[] countries;
}


bool Language::get_left_to_right() const
{
	return left_to_right;
}


int Language::get_num_of_letters() const
{
	return num_of_letters;
}


int Language::get_num_of_countries() const
{
	return num_of_countries;
}


std::string Language::get_name() const
{
	return name;
}


Language Language::operator= (const Language& other)
{
	name = other.name;
	left_to_right = other.left_to_right;
	num_of_letters = other.num_of_letters;
	num_of_countries = other.num_of_countries;
	delete[] countries;
	countries = new std::string[num_of_countries];
	for (int i = 0; i < num_of_countries; i++)
	{
		countries[i] = other.countries[i];
	}

	return *this;
}


std::ostream& operator<<(std::ostream& os, Language& language)
{
	os << "Name: " << language.name << std::endl;
	if (language.left_to_right)
		os << "Left to right" << std::endl;
	else
		os << "Right to left" << std::endl;
	os << "Num of letters: " << language.num_of_letters << std::endl;
	os << "Countries: " << std::endl;
	for (int i = 0; i < language.num_of_countries; i++)
	{
		os << language.countries[i] << ", ";
	}
	os << std::endl;

	return os;
}
