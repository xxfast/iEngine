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
#include <math.h>
#include "Predicate.h"

class TruthTable {
    
private:
    // MARK: Members
    vector<vector<bool>> fValues;
public:
    // MARK: Constructors
    TruthTable(vector<Predicate> aListOfPredicates, vector<Variable> aListOfVariables);
    
    // MARK: Member functions
};

#endif /* TruthTable_hpp */
