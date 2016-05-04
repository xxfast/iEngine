//
//  Predicate.cpp
//  iEngine
//
//  Created by Isuru Kusumal Rajapakse on 5/4/16.
//  Copyright © 2016 Isuru Kusumal Rajapakse. All rights reserved.
//


#include <sstream>
#include "Predicate.h"

using namespace std;


Predicate::Predicate()
{
    
}

Predicate::Predicate(string aInputString)
{
    vector<string> lStrings =  split(aInputString,';');
    cout << lStrings[0] << endl;
}

vector<string> Predicate::split(string str, char delimiter) {
    vector<string> internal;
    stringstream ss(str);
    string tok;
    while(getline(ss, tok, delimiter)) internal.push_back(tok);
    return internal;
}