//
//  Utilities.cpp
//  iEngine
//
//  Created by Ian Adrian Wisata Isuru Kusumal Rajapakse Srisaiyeegharan Kidnapillai on 5/4/16.
//  Copyright � 2016 Isuru Kusumal Rajapakse. All rights reserved.
//

#include "Utilities.h"
#include <fstream>
#include <stdexcept>


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

Predicate Utilities::stringToPredicate(string aString)
{
    
    Variable fLVal;
    Variable fRVal = "";
    Connective fConnective = NILL;
    
    Connective lAllPossibleConnectives[5] = {NOT,AND,OR,EQU,IMPLY};
    
    for (int i=0; i<5; i++)
    {
        string toSearch = connectiveToString(lAllPossibleConnectives[i]);
        size_t lPosition = aString.find(toSearch);
        if(lPosition!=string::npos)
        {
            fConnective = lAllPossibleConnectives[i];
            fRVal = aString.substr(lPosition+toSearch.size(),aString.size()-lPosition+toSearch.size());
            fLVal = aString.substr(0,aString.size()-fRVal.size()-toSearch.size());
            break;
        }
    }
    
    if(fConnective==NILL) fLVal = aString;
    
    Predicate* myPredicate = new Predicate(fLVal,fRVal,fConnective);
    return *myPredicate;
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

vector<Predicate>  Utilities::generatePredicates(ifstream& aInput)
{
	vector<string> lFirstLine;
	vector<string> lSecondLine;
	vector<Predicate> result;
	if (!aInput.good())
	{
        throw domain_error("Bad Input");
    }
    
    for (int i = 0; i < 4; i++)
    {
        getline(aInput, lFirstLine[i], '\n');
    }
    lSecondLine = splice(lFirstLine[1], ';');
    
    for (int i = 0; i < lSecondLine.size(); i++)
    {
        result[i] = Predicate(stringToPredicate(lSecondLine[i]));
    }
    
    return result;
}

