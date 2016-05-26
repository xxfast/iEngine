 //
//  CompoundPredicate.cpp
//  iEngine
//
//  Created by Srisaiyeegharan Kidnapillai on 5/20/16.
//  Copyright � 2016 Isuru Kusumal Rajapakse. All rights reserved.
//

#include "CompoundPredicate.h"
#include "Utilities.h"
#include "Predicate.h"



CompoundPredicate::CompoundPredicate(Predicate aLeftPredicate, Predicate aRightPredicate, Connective aConnective)
{
	fLVal = aLeftPredicate; 
	fRVal = aRightPredicate; 
	fConnective = aConnective; 
}

CompoundPredicate::~CompoundPredicate()
{
}


int CompoundPredicate::getPredicateCount(Predicate& aPredicate)
{
	int lResult = 0;
	Predicate lPredicate = aPredicate;
	if (!aPredicate.isLiteral())
	{
		lResult++;
		while (lPredicate.getLeft().size() != 1)
		{
			lResult++;
			lPredicate = Utilities::stringToPredicate(aPredicate.getLeft());
		}
	}
	return lResult;
}

vector<Predicate>& CompoundPredicate::getPredicates() const
{
    vector<Predicate>& lPredicates = *new vector<Predicate>();
    lPredicates.push_back(fLVal);
    lPredicates.push_back(fRVal);
    return lPredicates;
}

vector<Variable>& CompoundPredicate::getVariables() const
{
    vector<Variable>* temp = new vector<Variable>;
    temp->insert(temp->end(), fLVal.getVariables().begin(), fLVal.getVariables().end());
    temp->insert(temp->end(), fRVal.getVariables().begin(), fRVal.getVariables().end());
    return *temp;
}

Predicate& CompoundPredicate::getLeft() const
{
    return (Predicate&)fLVal;
}

Predicate& CompoundPredicate::getRight() const
{
    return (Predicate&)fRVal;
}

ostream& operator<<(ostream& aOStream ,CompoundPredicate& aCompoundPredicate)
{
    aOStream << aCompoundPredicate.getLeft() << Utilities::connectiveToString(aCompoundPredicate.getConnective()) << aCompoundPredicate.getRight();
    return aOStream;
}


