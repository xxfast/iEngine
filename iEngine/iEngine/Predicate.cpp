//
//  Predicate.cpp
//  iEngine
//
//  Created by Isuru Kusumal Rajapakse on 5/4/16.
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

bool Predicate::isLiteral()
{
    return (fConnective==NILL) && (fRVal=="");
}

vector<Variable> Predicate::getVariables()
{
    vector<Variable>* temp = new vector<Variable>;
    if (fLVal!="") temp->push_back(fLVal);
    if (fRVal!="") temp->push_back(fRVal);
    return *temp;
}

Variable Predicate::getLeft()
{
    return fLVal;
}

Variable Predicate::getRight()
{
    return fRVal;
}

Connective Predicate::getConnective()
{
	return fConnective;
}

ostream& operator<<(ostream& aOStream ,Predicate& aPredicate)
{
    return aOStream;
}

