#include "Utilities.h"
#include "Predicate.h"
#include "IEngine.h"

#pragma once
class BackwardChaining
{
private:
	bool fStatus;
	vector<Predicate> fAgenda;
	vector<Predicate> fInferred;
	vector<Predicate> fPredicates;
	map<Predicate, int> fHorn;
	

public:
	BackwardChaining();
	BackwardChaining(vector<Predicate> aPredicates);
	~BackwardChaining();
	vector<Predicate> evaluate(map<Predicate, int> aHorn, Predicate aAsked);
};

