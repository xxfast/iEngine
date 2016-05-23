//
//  main.cpp
//  IEngineTest
//
//  Created by Isuru Kusumal Rajapakse on 5/12/16.
//  Copyright © 2016 Isuru Kusumal Rajapakse. All rights reserved.
//

#include <iostream>

#include "TestUtilities.cpp"
#include "TestTruthTable.cpp"
#include "TestPredicate.cpp"
#include "TestIEngine.cpp"

using namespace std;

int main(int argc, const char * argv[])
{
    cout << "Test Suite" <<endl;
    TestTruthTable();
    TestUtilities();
    TestIEngine();
    TestPredicate();
    
    return 0;
}
