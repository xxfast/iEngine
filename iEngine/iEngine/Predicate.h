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

//Enumeration of connectives
enum Connective {NILL,NOT,IMPLY,AND,OR,EQU};

class Predicate
{
protected:
    Connective fConnective; //operation between the value
    
private:
    Variable fLVal; //left side variable
    Variable fRVal; //right side variable
public:
    // MARK: Constructors
    Predicate();
	// Default Constructor
    Predicate(Variable aLeftVariable, Variable aRightVariable, Connective aConnective); 
    
    // MARK: Member Functions
    
    // MARK: Setter and Getters
    
	//Check whether a predicate is a Literal
    bool isLiteral() const;
	//Check whether a predicate is horn
	bool isHorn() const;
    Variable getLiteral() const;
	//Returns a vector of variables from predicate.
    vector<Variable> getVariables() const;
	//Returns the left variable of a predicate
    Variable getLeft() const;
	//Returns the right variable of a predicate
    Variable getRight() const;
	//Returns the connective of a predicate
	virtual Connective getConnective() const;
    
    // MARK: Friends
    friend ostream& operator<<(ostream& aOStream ,Predicate& aPredicate);
    friend bool operator==(const Predicate& aLHS ,const Predicate& aRHS);
    friend bool operator<(const Predicate& aLHS ,const Predicate& aRHS);
};

#endif /* Predicate_h */
