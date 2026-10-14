#pragma once
#include <iostream>
#include "class2.h"
#include <random>
//#include "class2.cpp"


class Kgram{
private:
    // attributes
    std::random_device rd;
    std::mt19937 gen;
    //int length;
    
public:
    // attributes
    std::string kgram;

    // Constructors:
    Kgram();
    Kgram(Distribution dist, std::mt19937 gen);
    Kgram(std::string in);

    // Methods
    std::string evolve(Distribution dist, int tot_char);
    std::string evolve_alpha(Distribution dist, int tot_char, float alpha);
    void print();
};
