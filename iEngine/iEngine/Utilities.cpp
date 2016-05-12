//
//  Utilities.cpp
//  iEngine
//
//  Created by Ian Adrian Wisata Isuru Kusumal Rajapakse on 5/4/16.
//  Copyright © 2016 Isuru Kusumal Rajapakse. All rights reserved.
//

#include "Utilities.h"
#include <fstream>


Utilities::Utilities()
{
}



Utilities::~Utilities()
{
}


//Split the string based on the delimiter and store it into a array of string
vector<string> Utilities::splice(string aString, char aDelimiter)
{
	vector<string> result;
	stringstream lStringStream(aString);
	string lToken;
	while (getline(lStringStream, lToken, aDelimiter)) result.push_back(lToken);
	return result;
}


Connective Utilities::stringToConnective(string aString)
{
	Connective result;
	if (aString == "=>") result = IMPLY;
	else if (aString == "<=>") result = EQU;
	else if (aString == "~") result = NOT;
	else if (aString == "^") result = AND;
	else result = OR;

	return result;
}
string Utilities::connectiveToString(Connective aConnective)
{
	string result;

	if (aConnective == IMPLY)result = "=>";
	else if (aConnective == EQU)result = "<=>";
	else if (aConnective == NOT)result = "~";
	else if (aConnective == AND)result = "^";
	else if (aConnective == OR)result = "\/";
	return result;
}

Method Utilities::stringToMethod(string aString)
{
	Method result;
	if (aString == "FC")result = FC;
	else if (aString == "BC")result = BC;
	else if (aString == "TT")result = TT;
	return result;
}


vector<Predicate>  Utilities::generatePredicates(ifstream& aInput)
{
	vector<string> lFirstLine;
	vector<string> lSecondLine;
	vector<Predicate> result;
	while (aInput.good())
	{
		for (int i = 0; i < 4; i++)
		{
			getline(aInput, lFirstLine[i], '\n');
		}
		lSecondLine = splice(lFirstLine[1], ';');
		
		for (int i = 0; i < lSecondLine.size(); i++)
		{
			result[i] = Predicate(lSecondLine[i]);
		}
		return result;
	}
}