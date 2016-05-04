#pragma once
#include <iostream>
#include <string.h>
#include <vector>
#include "Predicate.h"

using namespace std;
class Utilities
{
public:
	Utilities();
	~Utilities();
	//Splice the string and return a predicate object
	vector<Predicate> spliceString(string aString);

	//Convert the String to a Connective
	Connective stringToConnective(string aString);

	//Convert the String to a Connective
	string connectinveToString(Connective aConnective);

};

