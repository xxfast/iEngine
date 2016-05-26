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
    
	// Takes a string and gets the predicate count
	int getPredicateCount(Predicate& aPredicate);
	
	// MARK: Member functions
    
    Predicate& getLeft() const;
    Predicate& getRight() const;
    vector<Predicate>& getPredicates() const;
    vector<Variable>& getVariables() const;
    
    // MARK: Friends
    friend ostream& operator<<(ostream& aOStream ,CompoundPredicate& aCompoundPredicate);

};



