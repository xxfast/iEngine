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
//Predicate constructor
Predicate::Predicate()
{
    fLVal="";
    fRVal="";
    fConnective=NILL;
}
//Predicate constructor
Predicate::Predicate(Variable aLeftVariable, Variable aRightVariable, Connective aConnective)
{
    fLVal = Utilities::stripSpaces(aLeftVariable);
    fRVal = Utilities::stripSpaces(aRightVariable);
    fConnective = aConnective;
}

//Check whether a predicate is a Literal
bool Predicate::isLiteral() const
{
    return ((fConnective==NILL) || (fConnective==NOT)) && ((fRVal=="")||(fLVal==""));
}

//Check whether a predicate is horn
bool Predicate::isHorn() const
{
	return (!(isLiteral()) && (fConnective == IMPLY));
}


Variable Predicate::getLiteral() const
{
    return (fLVal!="")?fLVal:fRVal;
}

//Returns a vector of variables from predicate.
vector<Variable> Predicate::getVariables() const
{
    vector<Variable>* temp = new vector<Variable>;
    if (fLVal!="") temp->push_back(fLVal);
    if (fRVal!="") temp->push_back(fRVal);
    return *temp;
}

//Returns the left variable of a predicate
Variable Predicate::getLeft() const
{
    return fLVal;
}

//Returns the right variable of a predicate
Variable Predicate::getRight() const
{
    return fRVal;
}

//Returns the connective of a predicate
Connective Predicate::getConnective() const
{
	return fConnective;
}

ostream& operator<<(ostream& aOStream ,Predicate& aPredicate)
{
    aOStream << aPredicate.getLeft() << Utilities::connectiveToString(aPredicate.getConnective()) << aPredicate.getRight();
    return aOStream;
}

bool operator==(const Predicate& aLHS ,const Predicate& aRHS)
{
    return (aLHS.getLeft()==aRHS.getLeft()) && (aLHS.getRight()==aRHS.getRight()) && (aLHS.getConnective()==aRHS.getConnective());
}
