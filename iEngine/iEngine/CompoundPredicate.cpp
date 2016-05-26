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

// Return a vector of predicates of a compound predicate
vector<Predicate>& CompoundPredicate::getPredicates() const
{
    vector<Predicate>& lPredicates = *new vector<Predicate>();
    lPredicates.push_back(fLVal);
    lPredicates.push_back(fRVal);
    return lPredicates;
}

// Return a vector of variables of a compound predicate
vector<Variable>& CompoundPredicate::getVariables() const
{
    vector<Variable>* temp = new vector<Variable>;
    vector<Variable> leftVariables = fLVal.getVariables();
    vector<Variable> rightVariables = fRVal.getVariables();
    for(int i=0;i<leftVariables.size();i++)
        temp->push_back(leftVariables[i]);
    for(int i=0;i<rightVariables.size();i++)
        temp->push_back(rightVariables[i]);
    return *temp;
}

// Get the left predicate of a compound predicate
Predicate& CompoundPredicate::getLeft() const
{
    return (Predicate&)fLVal;
}

// Get the right predicate of a compound predicate
Predicate& CompoundPredicate::getRight() const
{
    return (Predicate&)fRVal;
}

ostream& operator<<(ostream& aOStream ,CompoundPredicate& aCompoundPredicate)
{
    aOStream << aCompoundPredicate.getLeft() << Utilities::connectiveToString(aCompoundPredicate.getConnective()) << aCompoundPredicate.getRight();
    return aOStream;
}

bool operator==(const CompoundPredicate& aLHS ,const CompoundPredicate& aRHS)
{
    return (aLHS.getLeft()==aRHS.getLeft()) && (aLHS.getRight()==aRHS.getRight()) && (aLHS.getConnective()==aRHS.getConnective());
}


