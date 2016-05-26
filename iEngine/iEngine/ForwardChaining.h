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

