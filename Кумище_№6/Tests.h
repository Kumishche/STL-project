#pragma once
#include "Language.h"
#include "Func.h"
#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <numeric>
#include <functional>
#include <fstream>

void Tests();

bool lessInNumOfLetters_test(Language l1, Language l2);
bool lessInNumOfCountries_test(Language l1, Language l2);
bool lessInName_test(Language l1, Language l2);
void findMoreThan_test(Language l1, std::string name);
void findMoreThan_test(Language l1, int num, int t);
