#include "Language.h"


Language::Language()
{
	name = "null";
	left_to_right = true;
	num_of_letters = 0;
	num_of_countries = 0;
}


Language::Language(std::string n, bool l, int num, int countries)
{
	name = n;
	left_to_right = l;
	num_of_letters = num;
	num_of_countries = countries;
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


std::ostream& operator<<(std::ostream& os, Language& language)
{
	os << "Name: " << language.name << std::endl;
	if (language.left_to_right)
		os << "Left to right" << std::endl;
	else
		os << "Right to left" << std::endl;
	os << "Num of letters: " << language.num_of_letters << std::endl;
	os << "Num of countries: " << language.num_of_countries << std::endl;
	return os;
}
