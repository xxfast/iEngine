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
    
    Predicate myPredicate(Utilities::stringToPredicate("P=>E"));
    vector<Predicate>* myPredicates = new vector<Predicate>();
    myPredicates->push_back(myPredicate);
    // Instatiate iEngine on the Heap
    IEngine* testEngine = new IEngine(*myPredicates);
    cout << testEngine->process(Method::TT, "P") <<endl;
    
    
    //Exit the program
    lInput.close();
	return 0;
}