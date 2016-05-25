//
//  Predicate.h
//  iEngine
//
//  Created by Isuru Kusumal Rajapakse on 5/4/16.
//  Copyright © 2016 Isuru Kusumal Rajapakse. All rights reserved.
//

#include <iostream>
#include <vector>
#include <map>
#include <string>

#ifndef Predicate_h
#define Predicate_h

using namespace std;

typedef string Variable;

enum Connective {NILL,NOT,IMPLY,AND,OR,EQU};

class Predicate
{
private:
    Variable fLVal; //left side variable
    Variable fRVal; //right side variable
    Connective fConnective; //operation between the value
public:
    // MARK: Constructors
    Predicate();
    Predicate(Variable aLeftVariable, Variable aRightVariable, Connective aConnective); // Default Constructor
    
    // MARK: Member Functions
    
    // MARK: Setter and Getters
    
    bool isLiteral();
	bool isHorn();
    Variable getLiteral();
    vector<Variable> getVariables();
    Variable getLeft();
    Variable getRight();
	Connective getConnective();

	// Takes a string and gets the predicate count
	int getPredicateCount(Predicate& aPredicate);
    
    // MARK: Friends
    
    friend ostream& operator<<(ostream& aOStream ,Predicate& aPredicate);

};

#endif /* Predicate_h */
