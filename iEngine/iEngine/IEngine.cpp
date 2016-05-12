#include "IEngine.h"

using namespace std;

IEngine::IEngine(vector<Predicate> aPredicates)
{
    //Analyse the predicates and generate the list of variables
    fPredicates = aPredicates;
    for(int i=(int)aPredicates.size()-1;i>=0;i--)
    {
        vector<Variable> temp = aPredicates[i].getVariables();
        for(int i=0;i<temp.size();i++)
            if(!alreadyMapped(temp[i]))
                fVariables.push_back(temp[i]);
    }
    
}

IEngine::~IEngine()
{
}

bool IEngine::alreadyMapped(Variable aVariable)
{
    for(int i=0;i<fVariables.size();i++)
    {
        if(fVariables[i]==aVariable) return true;
    }
    return false;
}

bool IEngine::evaluateUsingTruthTable()
{
    //Translate the predicates into a truth table
    //TruthTable* truth = new TruthTable(fPredicates);
    //See if the
    return false;
}

bool IEngine::process(Method aMethod)
{
    bool result;
    switch (aMethod)
    {
        case TT:
            result = evaluateUsingTruthTable();
            break;
        default:
            result = evaluateUsingTruthTable(); //Defaults to TT
            break;
    }
    return result;
}