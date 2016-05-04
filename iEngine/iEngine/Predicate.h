//
//  Predicate.h
//  iEngine
//
//  Created by Isuru Kusumal Rajapakse on 5/4/16.
//  Copyright © 2016 Isuru Kusumal Rajapakse. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>

#ifndef Predicate_h
#define Predicate_h

using namespace std;

enum Connective {NOT,IMPLY,AND,OR,EQU};

class Predicate
{
private:
    vector<string> fVariables;
    vector<Connective> fConnectives;
    vector<string> split(string str, char delimiter);
public:
    Predicate();
    Predicate(string aInputString); // Default Constructor
};

#endif /* Predicate_h */
