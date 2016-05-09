#include "IEngine.h"

using namespace std;

IEngine::IEngine(vector<Predicate>)
{
    
}

IEngine::~IEngine()
{
}

bool IEngine::evaluateUsingTruthTable()
{
    
    return false;
}

bool IEngine::evaluate(Method aMethod)
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