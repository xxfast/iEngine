#include "BackwardChaining.h"

BackwardChaining::BackwardChaining()
{
}


BackwardChaining::~BackwardChaining()
{
}

BackwardChaining::BackwardChaining(vector<Predicate*> aPredicates)
{
	for (int i = 0; i < aPredicates.size() - 1; i++)
	{
		HornRecord lHorn;
		if (!aPredicates[i]->isLiteral() && aPredicates[i]->isHorn()) // if it's not literal and it's horn
		{
			lHorn.fPredicate = aPredicates[i];
			lHorn.fCount = 1;
			fHorns.push_back(lHorn);
		}
	}
}

vector<Variable> BackwardChaining::evaluate(Variable aVariableAsked)
{

	fAgenda.push_back(aVariableAsked); //push the asked to the agenda
	while (!fAgenda.empty())
	{
		fInferred.push_back(fAgenda.back());
		fAgenda.pop_back();

		for (int i = 0; i < fHorns.size() - 1; i++)
		{

			auto* lPredicate = dynamic_cast<CompoundPredicate *>(fHorns[i].fPredicate);

			if (lPredicate != NULL) //Compound Predicate
			{
				if (lPredicate->getRight().getLeft() == fInferred.back())
				{
					fHorns[i].fCount--;
					if (fHorns[i].fCount == 0)
						fAgenda.push_back(lPredicate->getRight().getLeft());
				}
			}
			else // Normal Predicate
			{
				if (fHorns[i].fPredicate->getRight() == fInferred.back())
				{
					fHorns[i].fCount--;
					if (fHorns[i].fCount == 0)
						fAgenda.push_back((fHorns[i].fPredicate->getLeft()));
				}
			}
		}
	}
	return fInferred;
}
