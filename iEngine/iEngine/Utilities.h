//  Utilities.h
//  iEngine
//
//  Created by Ian Adrian Wisata Isuru Kusumal Rajapakse Srisaiyeegharan Kidnapillai on 5/4/16.
//  Copyright � 2016 Isuru Kusumal Rajapakse. All rights reserved.
//

#pragma once
#include <iostream>
#include <string.h>
#include <vector>
#include <sstream>

#include "IEngine.h"
#include "Predicate.h"

using namespace std;
class Utilities
{
public:
	Utilities();
	~Utilities();
    
	//Splice the string and return a predicate object
    static vector<string> splice(string aString, char aDelimiter);
 
	//Convert the String to a Connective
	static Connective stringToConnective(string aString);
    
    //Convert the String to a Predicate
    static Predicate* stringToPredicate(string aString);
    static Predicate* stringToCompoundPredicates(string aString);
     
	//Convert the String to a Connective
	static string connectiveToString(Connective aConnective);

    // Takes an input file stream as the input
    // and and generates a vector of predicates from each the input
    // and return the vector of predicates
    static vector<Predicate*> generatePredicates(ifstream& aInput);
    
    // Takes a string and convert it to others
    static Method stringToMethod(string aString);

	//convert a predicate to string
    static string predicateToString(Predicate& aPredicate);

	//Remove the white spaces from a line of string
	static string stripSpaces(string input);
	
};