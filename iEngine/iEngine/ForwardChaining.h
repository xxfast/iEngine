//  ForwardChaining.h
//  iEngine
//
//  Created by Ian Adrian Wisata on 5/25/16.
//  Copyright © 2016 Ian Adrian Wisata. All rights reserved.
//

#pragma once
#include "Utilities.h"
#include "Predicate.h"
#include "IEngine.h"
#include <vector>
#include <queue>

using namespace std;

struct HornRecord 
{
	Predicate* fPredicate;
	int fCount;
};

class ForwardChaining
{
private:
	bool fStatus;
	queue<Variable> fAgenda;
	queue<Variable> fInferred;
	vector<HornRecord> fHorns;

public:
	ForwardChaining();
	ForwardChaining(vector<Predicate*> aPredicates);
	queue<Variable>evaluate(Variable aVariableAsked);
};

