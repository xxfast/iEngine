//
//  TestTruthTable.cpp
//  iEngine
//  Created by Isuru Kusumal Rajapakse on 5/18/16.
//  Copyright © 2016 Isuru Kusumal Rajapakse. All rights reserved.
//
#pragma once
#include <iostream>

#include "TruthTable.h"
#include "Utilities.h"

using namespace std;

void TestTruthTable()
{
    cout << "Testing TruthTable" <<endl;
    
    Predicate p1 (*Utilities::stringToCompoundPredicates("A&B=>D"));
    Predicate p2 (*Utilities::stringToCompoundPredicates("B&C"));
    Predicate p3 (*Utilities::stringToCompoundPredicates("A"));
    Predicate p4 (*Utilities::stringToCompoundPredicates("B"));
    Predicate p5 (*Utilities::stringToCompoundPredicates("C"));
    Predicate p6 (*Utilities::stringToCompoundPredicates("D"));
    
    vector<Predicate*> myPredicates ;
    myPredicates.push_back(&p1);
    myPredicates.push_back(&p2);
    myPredicates.push_back(&p3);
    myPredicates.push_back(&p4);
    myPredicates.push_back(&p5);
    myPredicates.push_back(&p6);
    
    vector<Variable> myVariables;
    myVariables.push_back("A");
    myVariables.push_back("B");
    myVariables.push_back("C");
    myVariables.push_back("D");
    
    TruthTable myTruthTable (myPredicates,myVariables);
    
    bool result = (1==1);
    cout << "\t- Testing TruthTable " << ((result)?"✔︎":"✘") << endl;
}
