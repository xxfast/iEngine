#pragma once
#include "Utilities.h"
#include "Predicate.h"
#include "IEngine.h"
#include <vector>

using namespace std;

class ForwardChaining
{
private:
	vector<Predicate> fAgenda;
	vector<Predicate> fInferred;
	map<Predicate, int> fHorn;

public:
	ForwardChaining();
	ForwardChaining(vector<Predicate> aPredicates);
	vector<Predicate> evaluate(map<Predicate, int> aHorn);
};

