#pragma once
#include <iostream>
#include <string.h>
#include <vector>
#include "Predicate.h"
#include <sstream>

using namespace std;
class Utilities
{
public:
	Utilities();
	~Utilities();
	//Splice the string and return a predicate object
    static vector<string> splice(string str, char delimiter);

	//Convert the String to a Connective
	static Connective stringToConnective(string aString);

	//Convert the String to a Connective
	static string connectinveToString(Connective aConnective);

};

