#pragma once
#include <random>
#include <iostream>
#include <map>

//using namespace std;

class Distribution
{
private:
    // Attributes
    std::vector<int> weights;
    std::discrete_distribution<> dist;

    // Methods
    std::string Read(std::string filename);
    std::map<std::string, int> Map_Gen(std::string text, int k);

public:
    // Attributes
    std::vector<std::string> names;

    // Generators
    Distribution();
    Distribution(std::string filename, int k, float alpha);

    // Methods
    std::string get_w(std::mt19937 gen);
    void print();
    char get_c(std::mt19937 gen, std::string kgram);
    char get_c_alpha(std::mt19937 gen, std::string kgram, float alpha);
};

