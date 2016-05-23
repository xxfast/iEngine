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

bool IEngine::evaluvatePredicate(Predicate aPredicate, map<Variable, bool> aKeyValues)
{
	//Evaluate the Given Predicate
	bool result = NULL;
	bool lLeft = aKeyValues[aPredicate.getLeft()];
	bool lRight = aKeyValues[aPredicate.getRight()];
	Connective lConnective = aPredicate.getConnective();

	if (!aPredicate.isLiteral())
	{
		if (lConnective == AND)result = (lLeft && lRight);
		else if (lConnective == OR)result = (lLeft || lRight);
		else if (lConnective == EQU)result = (lLeft == lRight);
		else if (lConnective == IMPLY)result = (!lLeft || lRight);
	}
	else
	{
		result = (lConnective == NOT)? !lRight: lLeft;
	}

	return result;
}


bool IEngine::alreadyMapped(Variable aVariable)
{
    for(int i=0;i<fVariables.size();i++)
    {
        if(fVariables[i]==aVariable) return true;
    }
    return false;
}

bool IEngine::evaluateUsingTruthTable(Variable aAsked)
{
    //Translate the predicates into a truth table
    TruthTable* truth = new TruthTable(fPredicates, fVariables);
    
    
    for(int i=0;i<(int)fPredicates.size();i++)
    {
        if(!fPredicates[i].isLiteral())
        {
            for(int j=0;j< truth->getRows(); j++)
            {
                map<Variable,bool> lKeyValues;
                lKeyValues[fPredicates[i].getLeft()]=truth->operator[](fPredicates[i].getLeft())[j];
                lKeyValues[fPredicates[i].getRight()]=truth->operator[](fPredicates[i].getRight())[j];
                bool result =evaluvatePredicate(fPredicates[i], lKeyValues);
                truth->data()[i][j] = result;
            }
        }
    }
    //cout << *truth;
    return truth->isInKnowledgeBase(aAsked);
}

bool IEngine::process(Method aMethod, Variable aAsked)
{
    bool result;
    switch (aMethod)
    {
        case TT:
            result = evaluateUsingTruthTable(aAsked);
            break;
        default:
            result =  evaluateUsingTruthTable(aAsked); //Defaults to TT
            break;
    }
    return result;
}