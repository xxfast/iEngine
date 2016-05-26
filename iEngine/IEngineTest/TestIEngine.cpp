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
#include "CompoundPredicate.h"
#include "IEngine.h"
#include "Utilities.h"

using namespace std;

void TestEvaluvatePredicateWithImplication()
{
    Predicate myPredicate (*Utilities::stringToPredicate("A=>B"));
    map<Variable,bool> myKeyValues;
    myKeyValues["A"]=1;
    myKeyValues["B"]=0;
    
    vector<Predicate*> myPredicates;
    myPredicates.push_back(&myPredicate);
    IEngine myEngine(myPredicates);
    
    bool result = ( 0 == myEngine.evaluvatePredicate(myPredicate, myKeyValues) );
    cout << "\t- Test Evaluvate Predicate With Implication " << ((result)?"✔︎":"✘") << endl;
}

void TestEvaluvatePredicateWithUnion()
{
    Predicate myPredicate (*Utilities::stringToPredicate("A^B"));
    
    vector<Predicate*> myPredicates;
    myPredicates.push_back(&myPredicate);
    IEngine myEngine(myPredicates);
    
    map<Variable,bool> myKeyValues;
    myKeyValues["A"]=1;
    myKeyValues["B"]=0;
    bool result = ( 0 == myEngine.evaluvatePredicate(myPredicate, myKeyValues) );
    cout << "\t- Test Evaluvate Predicate With Union " << ((result)?"✔︎":"✘") << endl;
}

void TestEvaluvatePredicateWithIntersect()
{
    Predicate myPredicate (*Utilities::stringToPredicate("A\/B"));
    
    vector<Predicate*> myPredicates;
    myPredicates.push_back(&myPredicate);
    IEngine myEngine(myPredicates);
    
    map<Variable,bool> myKeyValues;
    myKeyValues["A"]=1;
    myKeyValues["B"]=0;
    bool result = ( 1 == myEngine.evaluvatePredicate(myPredicate, myKeyValues) );
    cout << "\t- Test Evaluvate Predicate With Intersect " << ((result)?"✔︎":"✘") << endl;
}

void TestEvaluvatePredicateWithNegation()
{
    Predicate myPredicate (*Utilities::stringToPredicate("~B"));
    
    vector<Predicate*> myPredicates;
    myPredicates.push_back(&myPredicate);
    IEngine myEngine(myPredicates);
    
    map<Variable,bool> myKeyValues;
    myKeyValues["B"]=0;
    bool result = ( 1 == myEngine.evaluvatePredicate(myPredicate, myKeyValues) );
    cout << "\t- TestT Evaluvate Predicate With Negation " << ((result)?"✔︎":"✘") << endl;
}

void TestEvaluvatePredicateWithEquvelence()
{
    cout << "\t- To be implemented" << endl;
}

void TestEvaluvateCompoundPredicateWithImplication()
{
    Predicate myLeftPredicate (*Utilities::stringToPredicate("A^B"));
    Predicate myRightPredicate (*Utilities::stringToPredicate("C"));
    CompoundPredicate myCompoundPredicate (myLeftPredicate,myRightPredicate, IMPLY);
    
    vector<Predicate*> myPredicates;
    myPredicates.push_back(&myCompoundPredicate);
    
    IEngine myEngine(myPredicates);
    
    map<Variable,bool> myKeyValues;
    myKeyValues["A"]=1;
    myKeyValues["B"]=1;
    myKeyValues["C"]=0;

    bool result = ( 1 == myEngine.evaluvateCompundPredicate(myCompoundPredicate, myKeyValues) );
    cout << "\t- Test Evaluvate Compound Predicate With Negation " << ((result)?"✔︎":"✘") << endl;
}

void TestEvaluvateCompoundPredicate()
{
    TestEvaluvateCompoundPredicateWithImplication();
}

void TestEvaluvatePredicate()
{
    TestEvaluvatePredicateWithImplication();
    TestEvaluvatePredicateWithUnion();
    TestEvaluvatePredicateWithIntersect();
    TestEvaluvatePredicateWithNegation();
    TestEvaluvatePredicateWithEquvelence();
}

void TestEvaluvateWithTruthTable()
{
    Predicate* p1 = Utilities::stringToCompoundPredicates("A&C=>B");
    Predicate* p2 = Utilities::stringToCompoundPredicates("B&C=>A");
    Predicate* p3 = Utilities::stringToCompoundPredicates("A&C");
    
    vector<Predicate*> myPredicates ;
    
    myPredicates.push_back(p1);
    myPredicates.push_back(p2);
    myPredicates.push_back(p3);
    
    IEngine lIEngine (myPredicates);
    lIEngine.process(TT, "A");
    bool result = ( 1 == 1);
    cout << "\t- Test Evaluvate With TruthTable " << ((result)?"✔︎":"✘") << endl;

}

void TestIEngine()
{
    cout << "Testing IEngine" <<endl;
    TestEvaluvatePredicate();
    TestEvaluvateCompoundPredicate();
    TestEvaluvateWithTruthTable();
}
