//
//  ForwardChaining.cpp
//  iEngine
//
//  Created by Ian Adrian Wisata on 5/25/16.
//  Copyright © 2016 Ian Adrian Wisata. All rights reserved.
//

#include "ForwardChaining.h"
ForwardChaining::ForwardChaining()
{

}

ForwardChaining::ForwardChaining(vector<Predicate> aPredicates)
{
	for (int i = 0; i < aPredicates.size() - 1; i++)
	{
		if (aPredicates[i].isLiteral())
			fAgenda.push_back(aPredicates[i]);
		else
		{
			if (aPredicates[i].isHorn())
			{
				fPredicates.push_back(aPredicates[i]);
			}
		}
	}
}

vector<Predicate> ForwardChaining::evaluate(map<Predicate, int> aHorn, Predicate aAsked)
{
	fInferred.push_back(fAgenda.back());
	fAgenda.pop_back();

	while (!fAgenda.empty())
	{

		fInferred.push_back(fAgenda.back());
		fAgenda.pop_back();

		if (fInferred.back() == aAsked)
			break;
		//loop through all the Predicates , and check the count if 0 push it to agenda, and check if its matching
		// if its matches decrease the count
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
