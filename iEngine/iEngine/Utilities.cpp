#include "Utilities.h"


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

static Connective stringToConnective(string aString)
{
	Connective result;
	if (aString == "=>") result = IMPLY;
	else if (aString == "<=>") result = EQU;
	else if (aString == "~") result = NOT;
	else if (aString == "^") result = AND;
	else result = OR;

	return result;
}
static string connectiveToString(Connective aConnective)
{
	string result;

	if (aConnective == IMPLY)result = "=>";
	else if (aConnective == EQU)result = "<=>";
	else if (aConnective == NOT)result = "~";
	else if (aConnective == AND)result = "^";
	else result = "v";
	return result;
}