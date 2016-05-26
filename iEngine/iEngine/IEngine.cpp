//  IEngine.cpp
//  iEngine
//
//  Created by Isuru Kusumal Rajapakse And Sri Srisaiyeegharan Kidnapillai on 5/4/16.
//  Copyright � 2016 Isuru Kusumal Rajapakse. All rights reserved.
//

#include "IEngine.h"

using namespace std;

IEngine::IEngine(vector<Predicate*> aPredicates)
{
    //Analyse the predicates and generate the list of variables
    fPredicates = aPredicates;
   
    for(int i=(int)aPredicates.size()-1;i>=0;i--)
    {
        auto* cp = dynamic_cast<CompoundPredicate *>(fPredicates[i]);
        vector<Variable> temp;
        if(cp==NULL)
            temp = fPredicates[i]->getVariables();
        else
            temp = cp->getVariables();
        
        for(int i=0;i<temp.size();i++)
            if(!alreadyMapped(temp[i]))
                fVariables.push_back(temp[i]);
    }
    
}

IEngine::~IEngine()
{
}

// IEngine evaluvates a predicate from given keyvalue pairs
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

// IEngine evaluvates a compound predicate from given keyvalue pairs
bool IEngine::evaluvateCompundPredicate(CompoundPredicate aCompoundPredicate, map<Variable, bool> aKeyValues)
{
    //Evaluate the Given Compund Predicate
    map<Variable,bool>& lCalculatedKeyValues = *new map<Variable,bool>();
    lCalculatedKeyValues["A"] = evaluvatePredicate(aCompoundPredicate.getLeft(), aKeyValues);
    lCalculatedKeyValues["B"] = evaluvatePredicate(aCompoundPredicate.getRight(), aKeyValues);
    Predicate toSolve ("A", "B", aCompoundPredicate.getConnective());
    bool answer = evaluvatePredicate(toSolve, lCalculatedKeyValues);
    return answer;
}

// Chekcs if the variable is already mapped
bool IEngine::alreadyMapped(Variable aVariable)
{
    for(int i=0;i<fVariables.size();i++)
    {
        if(fVariables[i]==aVariable) return true;
    }
    return false;
}

// Maps the predicates to a given key values
map<Variable,bool>& IEngine::mapKeyValues(Predicate* aPredicate, TruthTable& truth, int indexToFetch, int indexToStore)
{
    map<Variable,bool>& lKeyValues = *new map<Variable,bool>();
    if (aPredicate->getLeft()!="")
    {
        lKeyValues[aPredicate->getLeft()] = truth.operator[](aPredicate->getLeft())[indexToFetch];
    }
    if (aPredicate->getRight()!="")
    {
        lKeyValues[aPredicate->getRight()]= truth.operator[](aPredicate->getRight())[indexToFetch];
    }
    return lKeyValues ;
}

// Maps the compound predicates to a given key values
map<Variable,bool>& IEngine::mapCompoundKeyValues(CompoundPredicate& aCompoundPredicate, TruthTable& truth, int indexToFetch, int indexToStore)
{
    Predicate* leftPredicate = &aCompoundPredicate.getLeft();
    Predicate* rightPredicate = &aCompoundPredicate.getRight();
    map<Variable,bool>& LeftKeyValues = mapKeyValues(leftPredicate,truth,indexToFetch,indexToStore);
    map<Variable,bool>& RightKeyValues = mapKeyValues(rightPredicate,truth,indexToFetch,indexToStore);
    LeftKeyValues.insert(RightKeyValues.begin(), RightKeyValues.end());
    return LeftKeyValues;
}

// evaluvate the knowledge base using Forward Chaining
bool IEngine::evaluateUsingFC(Variable aAsked)
{
    ForwardChaining FC = ForwardChaining(fPredicates);
    queue<Variable> results = FC.evaluate(aAsked);
    bool result = (results.back()==aAsked);
    while(!results.empty())
    {
        fResults+=results.front()+((results.size()!=1)?", ":"");
        results.pop();
    }
    return result;
}

// evaluvate the knowledge base using Backward Chaining
bool IEngine::evaluateUsingBC(Variable aAsked)
{
    BackwardChaining BC = BackwardChaining(fPredicates);
    vector<Variable> results = BC.evaluate(aAsked);
    bool result = (results.front()==aAsked);
    while(!results.empty())
    {
        fResults+=results.back()+((results.size()!=1)?", ":"");
        results.pop_back();
    }
    return result;
}

// evaluvate the knowledge base using Truth Tables
bool IEngine::evaluateUsingTruthTable(Variable aAsked)
{
    // Translate the predicates into a truth table
    TruthTable* truth = new TruthTable(fPredicates, fVariables);
    
    // Calculating values
    for(int i=0;i<(int)fPredicates.size();i++)
    {
        if(!fPredicates[i]->isLiteral())
        {
            for(int j=0;j< truth->getRows(); j++)
            {
                bool result;
                auto* cp = dynamic_cast<CompoundPredicate *>(fPredicates[i]);
                if( cp==NULL )
                    result = evaluvatePredicate(*fPredicates[i], mapKeyValues(fPredicates[i],*truth,j,i));
                else
                    result = evaluvateCompundPredicate(*cp, mapCompoundKeyValues(*cp,*truth,j,i));
                truth->data()[i][j] = result;
            }
        }
    }
    
    vector<bool> KB = truth->generateKnowledge(fPredicates);
    
    vector<int> askedIndexes;
    for (int i=0; i<fPredicates.size(); i++)
    {
        askedIndexes.push_back(truth->indexOf(fPredicates[i]));
    }
    
    bool rowAllTrue = true;
    int askedVariableIndex = truth->indexOfVariable(aAsked);
    
    for(int i=0;i<KB.size();i++)
    {
        bool truthDerived = truth->data()[askedVariableIndex][i];
        if(KB[i]!=truthDerived)
        {
            rowAllTrue = false;
            break;
        }
    }
    
    return rowAllTrue;
}

// Determine truth using the given method
bool IEngine::process(Method aMethod, Variable aAsked)
{
    bool result;
    switch (aMethod)
    {
        case TT:
            result = evaluateUsingTruthTable(aAsked);
            break;
        case FC:
            result = evaluateUsingFC(aAsked);
            break;
        case BC:
            result = evaluateUsingBC(aAsked);
            break;
        default:
            //Defaults to TT
            result = evaluateUsingTruthTable(aAsked);
            break;
    }
    return result;
}

// Get results from if the method generated results
string IEngine::getResults() const
{
    return fResults;
}

