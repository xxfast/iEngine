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
    
    for(int i=(int)aListOfPredicates.size()-1;i>=0;i--)
    {
        if(aListOfPredicates[i].isLiteral())
        {
            bool lSwitch = 0;
            for(int j=0;j< fNRows; j++)
            {
                i++;
                if ( i < pow(2,currentPredicate) )
                {
                    lSwitch=!lSwitch;
                    i = 0;
                }
                fValues[j][i] = lSwitch;
            }
        }
    }    
}
bool TruthTable::operator()(int r, int c)
{
    return fValues[r][c];
}

bool TruthTable::isInKnowledgeBase(Variable aAsked)
{
    return true;
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