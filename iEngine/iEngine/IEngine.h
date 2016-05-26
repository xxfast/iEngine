//  IEngine.h
//  iEngine
//
//  Created by Isuru Kusumal Rajapakse And Sri Srisaiyeegharan Kidnapillai on 5/4/16.
//  Copyright © 2016 Isuru Kusumal Rajapakse. All rights reserved.
//

#pragma once

#include <vector>
#include "Predicate.h"
#include "CompoundPredicate.h"
#include "TruthTable.h"

using namespace std;

enum Method {TT,FC,BC};

class IEngine
{
private:
    vector<Predicate*> fPredicates;
    vector<Variable> fVariables;
    
    // MARK: Private Member function
    bool evaluateUsingTruthTable(Variable aAsked);
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
};