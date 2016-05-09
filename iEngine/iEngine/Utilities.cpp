#include "Utilities.h"


Utilities::Utilities()
{
}

Utilities::~Utilities()
{
}

//Helper function

vector<string> Utilities::splice(string str, char delimiter)
{
    vector<string> internal;
    stringstream ss(str);
    string tok;
    while(getline(ss, tok, delimiter)) internal.push_back(tok);
    return internal;
}