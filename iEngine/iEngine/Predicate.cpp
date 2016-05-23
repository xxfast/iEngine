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

Predicate::Predicate(string aInputString)
{
    fLVal = aInputString[0];
    
    if(aInputString.length()==1)
       fRVal = "";
    else
       fRVal = aInputString[aInputString.length()-1];
    
    if (aInputString.length()>=1)
        fConnective = NILL;
    else if(aInputString.length()>=4)
        fConnective = Utilities::stringToConnective(aInputString.substr(1,2));
    else
        fConnective = Utilities::stringToConnective(aInputString.substr(1,1));
    
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