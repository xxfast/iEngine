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
    vector<string> lStrings =  Utilities::splice(aInputString,';');
    cout << lStrings[0] << endl;
}

ostream& operator<<(ostream& aOStream ,Predicate& aPredicate)
{
    for(int i=0;i<aPredicate.fConnectives.size();i++)
    {
        aOStream << aPredicate.fVariables[i] << " " << aPredicate.fConnectives[i] << " " << aPredicate.fVariables[i+1];
    }
    return aOStream;
}