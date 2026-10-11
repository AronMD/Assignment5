#pragma once

#include <iostream>

using namespace std;

class Distribution
{
private:
    string Read(string filename);

public:
    Distribution();
    Distribution(string filename,int k);


};

