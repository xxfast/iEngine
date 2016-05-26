//  Utilities.cpp
//  iEngine
//
//  Created by Ian Adrian Wisata, Isuru Kusumal Rajapakse, Srisaiyeegharan Kidnapillai on 5/4/16.
//  Copyright © 2016 Isuru Kusumal Rajapakse. All rights reserved.
//

#include "Utilities.h"
#include <fstream>
#include <stdexcept>
#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>

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
	else if (aString == "&") result = AND;
	else result = OR;

	return result;
}

Predicate* Utilities::stringToPredicate(string aString)
{
	Variable lLVal;
	Variable lRVal = "";
	Connective lConnective = NILL;

	// Reverse order of Evaluation
	Connective lAllPossibleConnectives[5] = { EQU,IMPLY,OR,AND,NOT };

	for (int i = 0; i<5; i++)
	{
		string toSearch = connectiveToString(lAllPossibleConnectives[i]);
		size_t lPosition = aString.find(toSearch);
		if (lPosition != string::npos)
		{
			lConnective = lAllPossibleConnectives[i];
			lRVal = aString.substr(lPosition + toSearch.size(), aString.size() - lPosition + toSearch.size());
			lLVal = aString.substr(0, aString.size() - lRVal.size() - toSearch.size());
			break;
		}
	}

	if (lConnective == NILL) lLVal = aString;
	Predicate* myPredicate = new Predicate(lLVal, lRVal, lConnective);
	return myPredicate;
}

Predicate* Utilities::stringToCompoundPredicates(string aString)
{
	int lConnectiveCount = 0;
	Connective lAllPossibleConnectives[5] = { EQU,IMPLY,OR,AND,NOT };

	for (int i = 0; i < 5; i++)
	{
		string toSearch = connectiveToString(lAllPossibleConnectives[i]);
		size_t lPosition = aString.find(toSearch);
		if (lPosition != string::npos)
		{
			lConnectiveCount++;
		}
	}
	
	if(lConnectiveCount<=1)
	{
		return stringToPredicate(aString);
	}
	else
	{
		Connective lCompoundConnective;
		Variable lLVal;
		Variable lRVal = "";

		for (int i = 0; i<5; i++)
		{
			string toSearch = connectiveToString(lAllPossibleConnectives[i]);
			size_t lPosition = aString.find(toSearch);
			if (lPosition != string::npos)
			{
				lCompoundConnective = lAllPossibleConnectives[i];
				lRVal = aString.substr(lPosition + toSearch.size(), aString.size() - lPosition + toSearch.size());
				lLVal = aString.substr(0, aString.size() - lRVal.size() - toSearch.size());
				break;
			}
		}
		Predicate* lLPredicate = stringToPredicate(lLVal);
		Predicate* lRPredicate = stringToPredicate(lRVal);

		CompoundPredicate* myCompoundPredicate = new CompoundPredicate(*lLPredicate, *lRPredicate, lCompoundConnective);
		return myCompoundPredicate;
	} 
}

string Utilities::connectiveToString(Connective aConnective)
{
	string result;

	if (aConnective == IMPLY)result = "=>";
	else if (aConnective == EQU)result = "<=>";
	else if (aConnective == NOT)result = "~";
	else if (aConnective == AND)result = "&";
	else if (aConnective == OR)result = "\/";
	return result;
}

string Utilities::predicateToString(Predicate& aPredicate)
{
    return aPredicate.getLeft()+connectiveToString(aPredicate.getConnective())+aPredicate.getRight();
}

Method Utilities::stringToMethod(string aString)
{
	Method result;
	if (aString == "FC")result = FC;
	else if (aString == "BC")result = BC;
	else if (aString == "TT")result = TT;
	return result;
}

vector<Predicate*>  Utilities::generatePredicates(ifstream& aInput)
{
	vector<string> stringPredicates;
	vector<Predicate*> result;
    
    string input;
    getline(aInput, input, '\n');
    
    if(input=="TELL")
    {
        getline(aInput, input, '\n');
        stringPredicates = splice(input, ';');
    }
    
    for (int i = 0; i < stringPredicates.size(); i++)
    {
        result.push_back(stringToCompoundPredicates(stringPredicates[i]));
    }
    
    return result;
}

string Utilities::stripSpaces(string input)
{
	input.erase(remove_if(input.begin(), input.end(), isspace), input.end());
	return input;
}


