#include "Utilities.h"


Utilities::Utilities()
{
}



Utilities::~Utilities()
{
}

Predicate Utilities::spliceString(char aString[])
{
	char* lPredicates;
	vector<Predicate> result;
	lPredicates = strtok(aString, ";");
	result.push_back(lPredicates)
	while (lPredicates != NULL)
	{

		lPredicates = strtok(NULL, ";");
		result.push_back(lPredicates)
	}

	return result;
}
