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
    
}

Predicate::Predicate(string aInputString)
{
    flVal = aInputString[0];
    fRVal = aInputString[aInputString.length()-1];
    if(aInputString.length()>=4)
        fConnective = Utilities::stringToConnective(aInputString.substr(1,2));
    else
        fConnective = Utilities::stringToConnective(aInputString.substr(1,1));
    
}

ostream& operator<<(ostream& aOStream ,Predicate& aPredicate)
{
    return aOStream;
}