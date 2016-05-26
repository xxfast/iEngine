#include "Utilities.h"
#include "Predicate.h"
#include "IEngine.h"


#pragma once
struct HornRecord
{
	Predicate* fPredicate;
	int fCount;
};

class BackwardChaining
{
private:
	bool fStatus;
	vector<Variable> fAgenda;
	vector<Variable> fInferred;
	vector<HornRecord> fHorns;


public:
	BackwardChaining();
	BackwardChaining(vector<Predicate*> aPredicates);
	~BackwardChaining();
	vector<Variable> evaluate(Variable aVariableAsked);
};

