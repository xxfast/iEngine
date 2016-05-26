//
//  ForwardChaining.h
//  iEngine
//
//  Created by Ian Adrian Wisata on 5/25/16.
//  Copyright � 2016 Ian Adrian Wisata. All rights reserved.
//

#pragma once
#include <vector>
#include <queue>
#include "HornRecord.h"

using namespace std;

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

