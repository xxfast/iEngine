//  IEngine.h
//  iEngine
//
//  Created by Isuru Kusumal Rajapakse And Sri Srisaiyeegharan Kidnapillai on 5/4/16.
//  Copyright © 2016 Isuru Kusumal Rajapakse. All rights reserved.
//

#pragma once

#include <vector>
#include <queue>

#include "TruthTable.h"
#include "ForwardChaining.h"
#include "BackwardChaining.h"

using namespace std;

enum Method {TT,FC,BC};

class IEngine
{
private:
    vector<Predicate*> fPredicates;
    vector<Variable> fVariables;
    string fResults;
    
    // MARK: Private Member function
    bool evaluateUsingTruthTable(Variable aAsked);
    bool evaluateUsingFC(Variable aAsked);
    bool evaluateUsingBC(Variable aAsked);
    map<Variable,bool>& mapKeyValues(Predicate* aPredicate, TruthTable& truth, int indexToFetch, int indexToStore);
    map<Variable,bool>& mapCompoundKeyValues(CompoundPredicate& aCompoundPredicate, TruthTable& truth, int indexToFetch, int indexToStore);
    bool alreadyMapped(Variable aVariable);
public:
    
    // MARK: Constructors
    IEngine(vector<Predicate*> aPredicates);
    ~IEngine();
    
    // MARK: Member function
    bool process(Method aMethod, Variable aAsked);
    bool evaluvatePredicate(Predicate aPredicate,map<Variable,bool> aKeyValues);
    bool evaluvateCompundPredicate(CompoundPredicate aCounpundPredicate,map<Variable,bool> aKeyValues);
    string getResults() const;
};