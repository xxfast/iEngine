//
//  TruthTable.cpp
//  iEngine
//
//  Created by Isuru Kusumal Rajapakse on 5/12/16.
//  Copyright © 2016 Isuru Kusumal Rajapakse. All rights reserved.
//

#include "TruthTable.h"

TruthTable::TruthTable(vector<Predicate>& aListOfPredicates, vector<Variable>& aListOfVariables)
{
    //Populate literals colomns first
    //Set number of columns to the size of predicates
    fNColumns = (int)aListOfPredicates.size();
    fNRows = pow(2,aListOfVariables.size());
    fValues.resize(fNRows,vector<bool>(fNColumns));
    
    int currentPredicate = (int)aListOfPredicates.size();
    
    for (int r = 0; r < fNRows ; r++)
    {
        int i = 0;
        bool lSwitch = 0;
        for(int c = 0; c < fNColumns ; c++)
        {
            bool literal = aListOfPredicates[--currentPredicate].isLiteral();
           
            if(literal)
            {
                i++;
                if ( i < pow(2,currentPredicate) )
                {
                    lSwitch=!lSwitch;
                    i = 0;
                }
                fValues[r][c] = lSwitch;
            }
            else
            {
                //Evaluvate Predicate
                fValues[r][c] = false;
            }
        }
    }
}
bool TruthTable::operator()(int r, int c)
{
    return fValues[r][c];
}

ostream& operator<<(ostream& aOutput, TruthTable& aTruthTable)
{
    for (int r = 0; r < aTruthTable.fNRows ; r++)
    {
        for(int c = 0; c< aTruthTable.fNColumns ; c++)
        {
            cout << setw(2) << aTruthTable(r,c);
        }
        cout << endl;
    }
    
    return aOutput;
}