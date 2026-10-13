#include "class1.h"
#include <iostream>
#include "class2.h"
//#include "class2.cpp"

// Constructor
Kgram::Kgram(){
    std::string kgram;
    length = 0;
};

Kgram::Kgram(int length, Distribution dist){
    
    // Choose w_k- first character 
    std::random_device rd;
    std::mt19937 gen(rd());
    std::string kgram = dist.get_w(gen);
    //std::cout << kgram << std::endl;

    // Look up the character distribution for w, and sample the next character c. 
    std::string reduced_kgram = kgram.erase(0, 1);
    //std::cout << reduced_kgram << std::endl;


    // If len of k == length then exit else repeat above - implies while
    
    //while(kgram.size()< length){}

}