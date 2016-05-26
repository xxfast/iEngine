//  IEngine.cpp
//  iEngine
//
//  Created by Isuru Kusumal Rajapakse And Sri Srisaiyeegharan Kidnapillai on 5/4/16.
//  Copyright © 2016 Isuru Kusumal Rajapakse. All rights reserved.
//

#include "IEngine.h"

using namespace std;

IEngine::IEngine(vector<Predicate*> aPredicates)
{
    //Analyse the predicates and generate the list of variables
    fPredicates = aPredicates;
   
    for(int i=(int)aPredicates.size()-1;i>=0;i--)
    {
        vector<Variable> temp = aPredicates[i]->getVariables();
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


bool IEngine::alreadyMapped(Variable aVariable)
{
    for(int i=0;i<fVariables.size();i++)
    {
        if(fVariables[i]==aVariable) return true;
    }
    return false;
}

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

map<Variable,bool>& IEngine::mapCompoundKeyValues(CompoundPredicate& aCompoundPredicate, TruthTable& truth, int indexToFetch, int indexToStore)
{
    Predicate* leftPredicate = &aCompoundPredicate.getLeft();
    Predicate* rightPredicate = &aCompoundPredicate.getRight();
    map<Variable,bool>& LeftKeyValues = mapKeyValues(leftPredicate,truth,indexToFetch,indexToStore);
    map<Variable,bool>& RightKeyValues = mapKeyValues(rightPredicate,truth,indexToFetch,indexToStore);
    LeftKeyValues.insert(RightKeyValues.begin(), RightKeyValues.end());
    return LeftKeyValues;
}


bool IEngine::evaluateUsingTruthTable(Variable aAsked)
{
    //Translate the predicates into a truth table
    TruthTable* truth = new TruthTable(fPredicates, fVariables);
    for(int i=0;i<(int)fPredicates.size();i++)
    {
        if(!fPredicates[i]->isLiteral())
        {
            for(int j=0;j< truth->getRows(); j++)
            {
                //map<Variable,bool> lKeyValues;
                //lKeyValues[fPredicates[i].getLeft()]=truth->operator[](fPredicates[i].getLeft())[j];
                //lKeyValues[fPredicates[i].getRight()]=truth->operator[](fPredicates[i].getRight())[j];
                bool result;
                //string test = typeid(fPredicates[i]).name();
                auto* cp = dynamic_cast<CompoundPredicate *>(fPredicates[i]);
                if( cp==NULL )
                {
                    result = evaluvatePredicate(*fPredicates[i], mapKeyValues(fPredicates[i],*truth,j,i));
                }
                else
                {
                    
                    result = evaluvateCompundPredicate(*cp, mapCompoundKeyValues(*cp,*truth,j,i));
                }
                truth->data()[i][j] = result;
            }
        }
    }
    cout << *truth;
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