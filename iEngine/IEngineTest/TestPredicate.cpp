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
    bool result = (1==1);
    cout << "\t- Testing Predicate " << ((result)?"✔︎":"✘") << endl;
}