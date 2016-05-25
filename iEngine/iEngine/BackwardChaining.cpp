#include "BackwardChaining.h"



BackwardChaining::BackwardChaining()
{
}


BackwardChaining::~BackwardChaining()
{
}

BackwardChaining::BackwardChaining(vector<Predicate> aPredicates)
{
	fStatus = false;
	for ( int i = 0; i < aPredicates.size() - 1; i++)
	{
		if (aPredicates[i].isHorn && !aPredicates[i].isLiteral())
		{
			fPredicates.push_back(aPredicates.back);
		}
	}
}

vector<Predicate> BackwardChaining::evaluate(map<Predicate, int> aHorn, Predicate aAsked)
{
	
	fAgenda.push_back(aAsked);

	while (!fAgenda.empty())
	{
		fInferred.push_back(fAgenda.back());
		fAgenda.pop_back();

		//for loop all the Predicates, check if the one that crossed is the asked then break
		if ( == aAsked)
			break;
		//minus the count and check if its 0 , add to the agenda

	}
	return fInferred;
}
