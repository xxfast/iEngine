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

ForwardChaining::ForwardChaining(vector<Predicate*> aPredicates)
{

	for (int i = 0; i < aPredicates.size(); i++)
	{
		if (aPredicates[i]->isLiteral())
			fAgenda.push(aPredicates[i]->getLeft());
		else
		{
			HornRecord lHorn;
			if (aPredicates[i]->isHorn())
			{
				auto test1 = dynamic_cast<CompoundPredicate*>(aPredicates[i]);
				auto* lPredicate = dynamic_cast<CompoundPredicate *>(aPredicates[i]);
				if (lPredicate != NULL)
				{
					lHorn.fPredicate = lPredicate;
					lHorn.fCount = fHorns[i].fCount = lPredicate->getLeft().getVariables().size();
					fHorns.push_back(lHorn);
					/*
					fHorns[i].fPredicate = lPredicate;
					fHorns[i].fCount = lPredicate->getLeft().getVariables().size();*/
				}
				else
				{
					lHorn.fPredicate = aPredicates[i];
					lHorn.fCount = 1;
					fHorns.push_back(lHorn);
					//fHorns[i].fPredicate = aPredicates[i];
					//fHorns[i].fCount = 1;
				}
			}
		}
	}
}

queue<Variable> ForwardChaining::evaluate(Variable aVariableAsked)
{
	//loop through all the Predicates , and check the count if 0 push it to agenda, and check if its matching
	while (!fAgenda.empty())
	{
		fInferred.push(fAgenda.front());
		fAgenda.pop();

		if (fInferred.front() == aVariableAsked) // do we compare pointer or?
			break;

		for (int i = 0; i < fHorns.size(); i++)
		{

			auto* lPredicate = dynamic_cast<CompoundPredicate *>(fHorns[i].fPredicate);

			if (lPredicate != NULL) //Compound Predicate
			{
				if (lPredicate->getLeft().getLeft() == fInferred.back())
				{
					fHorns[i].fCount--;
					if (fHorns[i].fCount == 0)
						fAgenda.push(lPredicate->getLeft().getLeft());
				}
				else if (lPredicate->getLeft().getRight() == fInferred.back())
				{
					fHorns[i].fCount--;
					if (fHorns[i].fCount == 0)
						fAgenda.push(lPredicate->getLeft().getRight());
				}
			}
			else // Normal Predicate
			{
				if (fHorns[i].fPredicate->getLeft() == fInferred.back())
				{
					fHorns[i].fCount--;
					if (fHorns[i].fCount == 0)
						fAgenda.push((fHorns[i].fPredicate->getLeft()));
				}
			}
		}
	}
	return fInferred;
}
