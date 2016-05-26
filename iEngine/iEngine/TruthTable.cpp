//  TruthTable.cpp
//  iEngine
//
//  Created by Isuru Kusumal Rajapakse on 5/12/16.
//  Copyright © 2016 Isuru Kusumal Rajapakse. All rights reserved.
//

#include "TruthTable.h"

TruthTable::TruthTable(vector<Predicate*>& aListOfPredicates, vector<Variable>& aListOfVariables)
{
    //Populate literals colomns first
    //Set number of columns to the size of predicates
    fPredicates = aListOfPredicates;
    
    for(int i=0;i<aListOfVariables.size();i++)
    {
        bool found = false;
        for(int j=0; j<aListOfPredicates.size();j++)
        {
            if(fPredicates[j]->isLiteral())
            {
                if(fPredicates[j]->getLiteral()==aListOfVariables[i])
                {
                    found = true;
                    break;
                }
            }
        }
        if(!found)
        {
            fPredicates.push_back(new Predicate(aListOfVariables[i],"",NILL));
        }
    }
    
    fNColumns = (int)fPredicates.size();
    fNRows = pow(2,aListOfVariables.size());
    
    //Populating the table
    fValues.resize(fNColumns);
    int d = (int)(fPredicates.size() - aListOfVariables.size()) - 1;
    for(int i=0;i<fPredicates.size();i++)
    {
        fValues[i].resize(fNRows);
        //Create values for literals first
        if(fPredicates[i]->isLiteral())
        {
            bool lSwitch = 0;
            int flip = 0;
            for(int j=0;j< fNRows; j++)
            {
                flip++;
                int tPow = pow(2,i-d)/2;
                if ( flip > tPow )
                {
                    lSwitch=!lSwitch;
                    flip= 1;
                }
                fValues[i][j] = lSwitch;
            }
        }
    }
}

vector<bool>& TruthTable::operator[] (Predicate aPredicate)
{
    for(int i=0;i<fPredicates.size();i++)
    {
        if(aPredicate==*fPredicates[i])
        {
            return fValues[i];
        }
    }
    throw domain_error("Predicate requested from the truth table is not found");
}

vector<bool>& TruthTable::operator[] (Variable aVariable)
{
    for(int i=0;i<fPredicates.size();i++)
    {
        if(fPredicates[i]->isLiteral())
        {
            if(aVariable ==fPredicates[i]->getLiteral())
            {
                return fValues[i];
            }
        }
    }
    throw domain_error("Predicate requested from the truth table is not found");
}

vector<vector<bool>>& TruthTable::data()
{
    return fValues;
}

bool TruthTable::isInKnowledgeBase(Variable aAsked)
{
    for (int i=0; i<fNColumns; i++)
    {
        
    }
    return true;
}

int TruthTable::getRows() const
{
    return fNRows;
}

int TruthTable::getCols() const
{
    return fNColumns;
}

ostream& operator<<(ostream& aOutput, TruthTable& aTruthTable)
{
    for(int i=0;i<aTruthTable.fNColumns;i++)
    {
        for(int j=0;j< aTruthTable.fNRows; j++)
        {
            cout << setw(2) <<aTruthTable.fValues[i][j];
        }
        auto* cp = dynamic_cast<CompoundPredicate *>(aTruthTable.fPredicates[i]);
        if( cp!=NULL )
            cout <<" - "<< i <<":"<< setw(4)<< *cp << endl;
        else
            cout <<" - "<< i <<":"<< setw(4)<< *aTruthTable.fPredicates[i] << endl;
            
    }
    return aOutput;
}