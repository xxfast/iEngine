#pragma once
#include "Utilities.h"
#include "Predicate.h"
#include "IEngine.h"
#include "ForwardChaining.h"

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

