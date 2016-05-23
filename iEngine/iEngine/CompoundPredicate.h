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
	CompoundPredicate(Predicate aPredicateOne, Predicate aPredicateTwo);

	~CompoundPredicate();

	// MARK: Member functions
};

