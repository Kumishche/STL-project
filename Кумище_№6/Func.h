#pragma once
#include "iostream"
#include "Language.h"

class Func
{
private:
	std::string name;

public:
	Func(std::string name) : name(name) {}

	bool operator() (const Language& lang) const 
	{
		return lang.get_name() == name;
	}
};