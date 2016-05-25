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

Predicate& CompoundPredicate::getLeft() const
{
    return (Predicate&)fLVal;
}

Predicate& CompoundPredicate::getRight() const
{
    return (Predicate&)fRVal;
}


Predicate CompoundPredicate::stringToCompoundPredicate(string aString)
{

	Variable lLVal;
	Variable lRVal = "";
	Variable lLCompoundLVal;
	Variable lLCompoundRVal;
					
	//Variable lRCompoundLVal;
	//Variable lRCompoundRVal;

	Connective fConnective = NILL;
	Connective lCompoundConnective = NILL;

	Connective lAllPossibleConnectives[5] = { NOT,AND,OR,EQU,IMPLY };

	for (int i = 0; i<5; i++)
	{
		string toSearch = Utilities::connectiveToString(lAllPossibleConnectives[i]);
		size_t lPosition = aString.find(toSearch);
		if (lPosition != string::npos)
		{
			fConnective = lAllPossibleConnectives[i];
			lRVal = aString.substr(lPosition + toSearch.size(), aString.size() - lPosition + toSearch.size());
			lLVal = aString.substr(0, aString.size() - lRVal.size() - toSearch.size());
			break;
		}
	}

	for (int i = 0; i < lLVal.size(); i++)
	{
		string toSearch = Utilities::connectiveToString(lAllPossibleConnectives[i]);
		size_t lPosition = lLVal.find(toSearch);
		if (lPosition != string::npos)
		{
			lCompoundConnective = lAllPossibleConnectives[i];
			lLCompoundRVal = aString.substr(lPosition + toSearch.size(), aString.size() - lPosition + toSearch.size());
			lLCompoundLVal = aString.substr(0, aString.size() - lLCompoundRVal.size() - toSearch.size());
			break;
		}

	}
	if (lCompoundConnective == NILL) lLCompoundLVal = aString;

	Predicate* myCompoundPredicate = new Predicate(lLCompoundLVal, lLCompoundRVal, lCompoundConnective);
	return *myCompoundPredicate;

}

