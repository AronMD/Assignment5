#pragma once
#include <random>
#include <iostream>
#include <map>

using namespace std;

class Distribution
{
private:
    // Attributes
    discrete_distribution<> dist;
    vector<string> names;
    vector<int> weights;
    string filename;
    int k;
    float alpha;

    // Methods
    string Read(string filename);
    map<string, int> Map_Gen(string text, int k);

public:
    // Generators
    Distribution();
    Distribution(string filename, int k, float alpha);

    // Methods
    string get_w();
};

