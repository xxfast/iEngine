//
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
	vector<Predicate> fAgenda;
	vector<Predicate> fInferred;
	vector<Predicate> fPredicates;
	vector<HornRecord> fHorns;

public:
	ForwardChaining();
	ForwardChaining(vector<Predicate> aPredicates);
	vector<Predicate> evaluate(map<Predicate, int> aHorn, Predicate aAsked);
};

