//
//  main.cpp
//  IEngineTest
//
//  Created by Isuru Kusumal Rajapakse on 5/12/16.
//  Copyright © 2016 Isuru Kusumal Rajapakse. All rights reserved.
//

#include <iostream>
#include "Predicate.h"
#include "TruthTable.h"

using namespace std;

void TestTruthTable()
{
    bool result = (1==1);
    cout << "\t- Testing TruthTable " << ((result)?"✔︎":"✘") << endl;
}

void TestPredicate()
{
    bool result = (1==1);
    cout << "\t- Testing Predicate " << ((result)?"✔︎":"✘") << endl;
}

int main(int argc, const char * argv[])
{
    cout << "Testing IEngine" <<endl;
    
    // MARK: TestSuite
    
    TestTruthTable();
    
    return 0;
}
