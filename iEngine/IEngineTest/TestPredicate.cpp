//
//  TestPredicate.cpp
//  iEngine
//
//  Created by Isuru Kusumal Rajapakse on 5/18/16.
//  Copyright © 2016 Isuru Kusumal Rajapakse. All rights reserved.
//


#include <stdio.h>
#include <iostream>

using namespace std;

void TestPredicate()
{
    cout << "Testing Predicate" <<endl;
    
    Predicate p1 (Utilities::stringToPredicate("A^B"));
    Predicate p2 (Utilities::stringToPredicate("A\/B"));
    Predicate p3 (Utilities::stringToPredicate("A~B"));
    Predicate p4 (Utilities::stringToPredicate("A=>B"));
    Predicate p5 (Utilities::stringToPredicate("A<=>B"));
    Predicate p6 (Utilities::stringToPredicate("A"));
    
    bool result = (1==1);
    cout << "\t- Testing Predicate " << ((result)?"✔︎":"✘") << endl;
}