//  BackwardChaining.h
//  iEngine
//
//  Created by Srisaiyeegharan Kidnapillai Ian Adrian Wisata on 5/20/16.
//  Copyright � 2016 Isuru Kusumal Rajapakse. All rights reserved.
//

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
	//Constructor
	BackwardChaining();
	BackwardChaining(vector<Predicate*> aPredicates);

	~BackwardChaining();

	vector<Variable> evaluate(Variable aVariableAsked);
};

