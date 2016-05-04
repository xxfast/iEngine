#include <iostream>
#include <fstream>
#include "Predicate.h"

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

	if (lInput.good())
	{
		cerr << "Opened input file " << argv[1] << endl;
		// program successfull
		return 0;
	}

	lInput.close();

	cout << "test" << endl;
	Predicate myPredicate("P=>E;");
	return 0;
}