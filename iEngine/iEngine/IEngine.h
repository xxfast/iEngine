//
//  IEngine.h
//  iEngine
//
//  Created by Isuru Kusumal Rajapakse And Sri Srisaiyeegharan Kidnapillai on 5/4/16.
//  Copyright © 2016 Isuru Kusumal Rajapakse. All rights reserved.
//

#pragma once

#include <vector>
#include "Predicate.h"

using namespace std;

enum Method {TT,FC,BC};

class IEngine
{
private:
    vector<Predicate> fPredicates;
    vector<Variable> fVariables;
    bool evaluateUsingTruthTable();
    bool alreadyMapped(Variable aVariable);
public:
    IEngine(vector<Predicate> aPredicates);  // defautl Constructors
    ~IEngine();
    
    bool evaluate(Method aMethod);
};