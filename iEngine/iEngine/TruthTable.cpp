//
//  TruthTable.cpp
//  iEngine
//
//  Created by Isuru Kusumal Rajapakse on 5/12/16.
//  Copyright © 2016 Isuru Kusumal Rajapakse. All rights reserved.
//

#include "TruthTable.h"

TruthTable::TruthTable(vector<Predicate> aListOfPredicates, vector<Variable> aListOfVariables)
{
    //Populate literals colomns first
    
    //Set number of columns to the size of predicates
    fValues.resize(aListOfPredicates.size());
    for(int i=fValues.size(); i<=0; i--)
    {
        //Set number of rows to 2^n
        fValues[i].resize(pow(2,aListOfVariables.size()));
        bool literal = aListOfPredicates[i].isLiteral();
        int literalCount = 1;
        bool switchCount = 1;
        for(int j=0;j>fValues[i].size();j++)
        {
            if(literal)
            {
                switchCount = !(j<pow(2,i));
                fValues[i][j] = switchCount ;
            }
        }
    }
}