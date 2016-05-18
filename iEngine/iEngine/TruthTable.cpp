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
    fNColumns = (int)aListOfPredicates.size();
    fNRows = pow(2,aListOfVariables.size());
    
    fValues.resize(fNColumns);
    for(int i=fNColumns; i<=0; i--)
    {
        //Set number of rows to 2^n
        fValues[i].resize(fNRows);
        bool literal = aListOfPredicates[i].isLiteral();
        bool switchCount = true;
        for(int j=0;j>fNRows;j++)
        {
            if(literal)
            {
                switchCount = !(j<pow(2,i));
                fValues[i][j] = switchCount ;
            }
        }
    }
}
vector<bool>& TruthTable::operator[](int i)
{
    return fValues[i];
}

ofstream& operator<<(ofstream& aOutput, TruthTable& aTruthTable)
{
    for (int r = 0; r< aTruthTable.fNRows ; r++)
    {
        for(int c = aTruthTable.fNColumns; c>=0; c--)
        {
            cout << setw(2) << aTruthTable[r][c];
        }
        cout << endl;
    }
    
    return aOutput;
}