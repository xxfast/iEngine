#include "ForwardChaining.h"



ForwardChaining::ForwardChaining()
{

}

ForwardChaining::ForwardChaining(vector<Predicate> aPredicates)
{
	Predicate lPredicate = aPredicates.back();
	aPredicates.pop_back();
	while (!aPredicates.empty())
	{
		if (lPredicate.isLiteral())
		{
			fAgenda.push_back(lPredicate);
		}
		else
		{
			{
			}
		}

	}

}

vector<Predicate> ForwardChaining::evaluate(map<Predicate, int> aHorn)
{
	fInferred.push_back(fAgenda.back());
	fAgenda.pop_back();

	while (!fAgenda.empty())
	{
		fInferred.push_back(fAgenda.back());
		fAgenda.pop_back();
		//for (auto& key : aHorn)
		//{
		//	if (key.first.getLeft() == fInferred.back().getLiteral())
		//	{
		//		key.second--;
		//		if (key.second == 0)
		//			fAgenda.push_back(key.first.getRight());
		//	}
		//}

	}
	return fInferred;
}
