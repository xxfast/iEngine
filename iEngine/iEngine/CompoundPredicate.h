//  CompoundPredicate.h
//  iEngine
//
//  Created by Srisaiyeegharan Kidnapillai on 5/20/16.
//  Copyright � 2016 Isuru Kusumal Rajapakse. All rights reserved.
//

#pragma once

#include "Predicate.h"

class CompoundPredicate : public Predicate
{
private:
	// MARK: Members
	Predicate fLVal; //left side Predicate
	Predicate fRVal; //right side Predicate
public:
	// MARK: Constructors	
	CompoundPredicate(Predicate aLeftPredicate, Predicate aRightPredicate, Connective aConnective);
    
	~CompoundPredicate();
   
	// MARK: Member functions
    
	// Get the left predicate of a compound predicate
    Predicate& getLeft() const;

	// Get the right predicate of a compound predicate
    Predicate& getRight() const;

	// Return a vector of predicates of a compound predicate
    vector<Predicate>& getPredicates() const;

	// Return a vector of variables of a compound predicate
    vector<Variable>& getVariables() const;
    
    // MARK: Friends
    friend ostream& operator<<(ostream& aOStream ,CompoundPredicate& aCompoundPredicate);

};



