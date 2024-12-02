#pragma once
#include <iostream>

class Language
{
private:
	std::string name;
	bool left_to_right;
	int num_of_letters;
	int num_of_countries;
	std::string* countries;

public:
	Language();
	Language(std::string n, bool l, int num, std::string* c, int size);
	Language(const Language& other);
	~Language();

	bool get_left_to_right() const;
	int get_num_of_letters() const;
	int get_num_of_countries() const;
	std::string get_name() const;

	Language operator= (const Language& other);
	friend std::ostream& operator<<(std::ostream& os, Language& language);
};