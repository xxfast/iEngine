//
//  TestIEngine.cpp
//  iEngine
//
//  Created by Isuru Kusumal Rajapakse on 5/18/16.
//  Copyright © 2016 Isuru Kusumal Rajapakse. All rights reserved.
//
#pragma once

#include <stdio.h>
#include <iostream>
#include <map>

#include "Predicate.h"
#include "IEngine.h"

using namespace std;

void TestEvaluvatePredicateWithImplication()
{
    Predicate myPredicate ("A=>B");
    map<Variable,bool> myKeyValues;
    myKeyValues["A"]=1;
    myKeyValues["B"]=0;
    
    vector<Predicate> myPredicates;
    myPredicates.push_back(myPredicate);
    IEngine myEngine(myPredicates);
    
    bool result = ( 0 == myEngine.evaluvatePredicate(myPredicate, myKeyValues) );
    cout << "\t- Test Evaluvate Predicate With Implication " << ((result)?"✔︎":"✘") << endl;
}

void TestEvaluvatePredicateWithUnion()
{
    Predicate myPredicate ("A&B");
    
    vector<Predicate> myPredicates;
    myPredicates.push_back(myPredicate);
    IEngine myEngine(myPredicates);
    
    map<Variable,bool> myKeyValues;
    myKeyValues["A"]=1;
    myKeyValues["B"]=0;
    bool result = ( 0 == myEngine.evaluvatePredicate(myPredicate, myKeyValues) );
    cout << "\t- Test Evaluvate Predicate With Union " << ((result)?"✔︎":"✘") << endl;
}

void TestEvaluvatePredicateWithIntersect()
{
    Predicate myPredicate ("A\/B");
    
    vector<Predicate> myPredicates;
    myPredicates.push_back(myPredicate);
    IEngine myEngine(myPredicates);
    
    map<Variable,bool> myKeyValues;
    myKeyValues["A"]=1;
    myKeyValues["B"]=0;
    bool result = ( 1 == myEngine.evaluvatePredicate(myPredicate, myKeyValues) );
    cout << "\t- Test Evaluvate Predicate With Intersect " << ((result)?"✔︎":"✘") << endl;
}

void TestEvaluvatePredicateWithNegation()
{
    Predicate myPredicate ("~B");
    
    vector<Predicate> myPredicates;
    myPredicates.push_back(myPredicate);
    IEngine myEngine(myPredicates);
    
    map<Variable,bool> myKeyValues;
    myKeyValues["B"]=0;
    bool result = ( 1 == myEngine.evaluvatePredicate(myPredicate, myKeyValues) );
    cout << "\t- Test Evaluvate Predicate With Negation " << ((result)?"✔︎":"✘") << endl;
}

void TestEvaluvatePredicateWithEquvelence()
{
    cout << "\t- To be implemented" << endl;
}

void TestEvaluvatePredicate()
{
    TestEvaluvatePredicateWithImplication();
    TestEvaluvatePredicateWithUnion();
    TestEvaluvatePredicateWithIntersect();
    TestEvaluvatePredicateWithNegation();
    TestEvaluvatePredicateWithEquvelence();
}

void TestIEngine()
{
    cout << "Testing IEngine" <<endl;
    TestEvaluvatePredicate();
}
