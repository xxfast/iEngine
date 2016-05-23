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
    static Predicate stringToPredicate(string aString);
     
	//Convert the String to a Connective
	static string connectiveToString(Connective aConnective);
    

	//Uncomment once implemented
    // Takes an input file stream as the input
    // and and generates a vector of predicates from each the input
    // and return the vector of predicates
    static vector<Predicate> generatePredicates(ifstream& aInput);
    
    // Takes a string and convert it to others
    static Method stringToMethod(string aString);
    static string predicateToString(Predicate& aPredicate);
     
    
};