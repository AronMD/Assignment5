#pragma once
#include <random>
#include <iostream>
#include <map>

using namespace std;

class Distribution
{
private:
    // Attributes
    vector<int> weights;
    discrete_distribution<> dist;

    // Methods
    string Read(string filename);
    map<string, int> Map_Gen(string text, int k);

public:
    // Attributes
    vector<string> names;

    // Generators
    Distribution();
    Distribution(string filename, int k, float alpha);

    // Methods
    string get_w();
    void print();
};

