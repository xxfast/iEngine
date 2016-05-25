//
//  CompoundPredicate.h
//  iEngine
//
//  Created by Srisaiyeegharan Kidnapillai on 5/20/16.
//  Copyright � 2016 Isuru Kusumal Rajapakse. All rights reserved.
//

#pragma once

#include "Predicate.h"
class CompoundPredicate
{
private:
	// MARK: Members
	Predicate fLVal; //left side Predicate
	Predicate fRVal; //right side Predicate
	Connective fConnective; //operation between the value
public:
	// MARK: Constructors	
	CompoundPredicate(Predicate aLeftPredicate, Predicate aRightPredicate, Connective aConnective);
	~CompoundPredicate();
	
	// MARK: Member functions


};



