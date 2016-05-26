#pragma once
#include "HornRecord.h"
#include <vector>
#include <queue>

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

