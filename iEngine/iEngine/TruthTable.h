//
//  TruthTable.hpp
//  iEngine
//
//  Created by Isuru Kusumal Rajapakse on 5/12/16.
//  Copyright © 2016 Isuru Kusumal Rajapakse. All rights reserved.
//

#ifndef TruthTable_hpp
#define TruthTable_hpp

#include <stdio.h>
#include <iostream>
#include <math.h>
#include <iomanip>
#include "Predicate.h"

using namespace std;

class TruthTable {
    
private:
    // MARK: Members
    vector<vector<bool>> fValues;
    int fNColumns;
    int fNRows;
public:
    // MARK: Constructors
    TruthTable(vector<Predicate> aListOfPredicates, vector<Variable> aListOfVariables);
    
    // MARK: Member functions
    vector<bool>& operator[](int r);
    
    // MARK: Friends
    friend ofstream& operator<<(ofstream& aOutput, TruthTable& aTruthTable);
};

#endif /* TruthTable_hpp */
