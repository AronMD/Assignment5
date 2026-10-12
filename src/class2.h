#pragma once

#include <iostream>
#include <map>

using namespace std;

class Distribution
{
private:
    string Read(string filename);
    map<string, int> Map_Gen(string text, int k);

public:
    Distribution();
    Distribution(string filename, int k, float alpha);


};

