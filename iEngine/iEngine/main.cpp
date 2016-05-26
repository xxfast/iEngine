//  main.cpp
//  iEngine
//
//  Created by Srisaiyeegharan Kidnapillai on 5/4/16.
//  Copyright � 2016 Isuru Kusumal Rajapakse. All rights reserved.
//

#include <iostream>
#include <fstream>
#include "Predicate.h"
#include "IEngine.h"
#include "Utilities.h"

using namespace std;

int main(int argc, char* argv[])
{
	if (argc < 1)
	{
		cerr << "Arguments missing" << endl;
		// program failed
		return 1;
	}

	// set up input file and declare an input file variable
	ifstream lInput;

	// open an input text file
	lInput.open(argv[1], ifstream::in);

	// If state of the stream is good
	if (!lInput.good())
	{
		cerr << "Cannot open input file: " << argv[1] << endl;
		// program failed (input)
		return 2;
	}

	if (!lInput.good())
	{
		cerr << "Couldn't open input file " << argv[1] << endl;
		// program failed (input)
		return 2;
	}
    
    
    cout << "iEngine Driver Program" << endl;
    
    Method lMethod = TT;
    if(argc>=2)
        lMethod = Utilities::stringToMethod(argv[2]);
    else
        cout << "Method not specified, defaults to TT" << endl;
    
    vector<Predicate*> lPredicates = Utilities::generatePredicates(lInput);
    
    // Instatiate iEngine on the Heap
    IEngine* testEngine = new IEngine(lPredicates);
    bool success = testEngine->process(lMethod, "d");
    string output;
    cout << ((success)?"YES":"NO")<< output<<": "<< testEngine->getResults()<<endl;
    
    //Exit the program
    lInput.close();
	return 0;
}