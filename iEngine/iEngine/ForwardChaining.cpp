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
	for (int i = 0; i < aPredicates.size() - 1; i++)
	{
		if (aPredicates[i]->isLiteral())
			fAgenda.push(aPredicates[i]->getLeft());
		else
		{
			if (aPredicates[i]->isHorn())
			{
				auto* lPredicate = dynamic_cast<CompoundPredicate *>(aPredicates[i]);
				if (lPredicate !=NULL)
				{
					fHorns[i].fPredicate = lPredicate;
					fHorns[i].fCount = lPredicate->getLeft().getVariables().size();
				}
				else
				{
					fHorns[i].fPredicate = lPredicate;
					fHorns[i].fCount = 1;
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

		for (int i = 0; i < fHorns.size() - 1; i++)
		{

			auto* lPredicate = dynamic_cast<CompoundPredicate *>(fHorns[i].fPredicate);

			if (lPredicate != NULL) //Compound Predicate
			{
				if (lPredicate->getLeft().getLeft() == aVariableAsked)
				{
					fHorns[i].fCount--;
					if (fHorns[i].fCount == 0)
						fAgenda.push(lPredicate->getLeft().getLeft());
				}
				else if (lPredicate->getLeft().getRight() == aVariableAsked)
				{
					fHorns[i].fCount--;
					if (fHorns[i].fCount == 0)
						fAgenda.push(lPredicate->getLeft().getRight());
				}
			}
			else // Normal Predicate
			{
				if (fHorns[i].fPredicate->getLeft() == aVariableAsked)
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
