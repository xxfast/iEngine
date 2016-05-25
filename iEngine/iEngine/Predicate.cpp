//
//  Predicate.cpp
//  iEngine
//
//  Created by Ian Adrian Wisata, Isuru Kusumal Rajapakse on 5/4/16.
//  Copyright © 2016 Isuru Kusumal Rajapakse. All rights reserved.
//


#include <sstream>
#include "Predicate.h"
#include "Utilities.h"

using namespace std;


Predicate::Predicate()
{
    fLVal="";
    fRVal="";
    fConnective=NILL;
}

Predicate::Predicate(Variable aLeftVariable, Variable aRightVariable, Connective aConnective)
{
    fLVal = aLeftVariable;
    fRVal = aRightVariable;
    fConnective = aConnective;
}

bool Predicate::isLiteral() const
{
    return ((fConnective==NILL) || (fConnective==NOT)) && ((fRVal=="")||(fLVal==""));
}

bool Predicate::isHorn() const
{
	return (!(isLiteral()) && (fConnective == IMPLY));
}

Variable Predicate::getLiteral() const
{
    return (fLVal!="")?fLVal:fRVal;
}

vector<Variable> Predicate::getVariables() const
{
    vector<Variable>* temp = new vector<Variable>;
    if (fLVal!="") temp->push_back(fLVal);
    if (fRVal!="") temp->push_back(fRVal);
    return *temp;
}

Variable Predicate::getLeft() const
{
    return fLVal;
}

Variable Predicate::getRight() const
{
    return fRVal;
}

Connective Predicate::getConnective() const
{
	return fConnective;
}

int Predicate::getPredicateCount(Predicate& aPredicate)
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


ostream& operator<<(ostream& aOStream ,Predicate& aPredicate)
{
    aOStream << aPredicate.getLeft() << aPredicate.getConnective() << aPredicate.getRight();
    return aOStream;
}

bool operator==(const Predicate& aLHS ,const Predicate& aRHS)
{
    return (aLHS.getLeft()==aRHS.getLeft()) && (aLHS.getRight()==aRHS.getRight()) && (aLHS.getConnective()==aRHS.getConnective());
}
