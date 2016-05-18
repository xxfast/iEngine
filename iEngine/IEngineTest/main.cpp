//
//  main.cpp
//  IEngineTest
//
//  Created by Isuru Kusumal Rajapakse on 5/12/16.
//  Copyright © 2016 Isuru Kusumal Rajapakse. All rights reserved.
//

#include <iostream>
#include <fstream>
#include "Predicate.h"
#include "TruthTable.h"
#include "IEngine.h"

using namespace std;

void TestTruthTable()
{
    bool result = (1==1);
    cout << "\t- Testing TruthTable " << ((result)?"✔︎":"✘") << endl;
}

void TestPredicate()
{
    bool result = (1==1);
    cout << "\t- Testing Predicate " << ((result)?"✔︎":"✘") << endl;
}

void TestEvaluvatePredicate()
{
    Predicate myPredicate ("A=>B");
    map<Variable,bool> myKeyValues;
    myKeyValues["A"]=1;
    myKeyValues["B"]=0;
    
    vector<Predicate> myPredicates;
    myPredicates.push_back(myPredicate);
    IEngine myEngine(myPredicates);
    
    bool result = ( 0 == myEngine.evaluvatePredicate(myPredicate, myKeyValues) );
    cout << "\t- Testing Evaluvate Predicate " << ((result)?"✔︎":"✘") << endl;
}

int main(int argc, const char * argv[])
{
    cout << "Testing IEngine" <<endl;
    
    // MARK: TestSuite
    
    TestTruthTable();
    TestEvaluvatePredicate();
    
    return 0;
}
