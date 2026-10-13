#include "class1.h"
#include <iostream>
#include "class2.h"
//#include "class2.cpp"

// Constructor
Kgram::Kgram(){
    std::string kgram = "";
    std::random_device rd;
    std::mt19937 gen(rd());
    //length = 0;
};


Kgram::Kgram(Distribution dist, std::mt19937 gen){
    // Choose w_k - first character 
    kgram = dist.get_w(gen);
    std::cout << "kgram in the constructor: " << kgram << std::endl;

};


Kgram::Kgram(std::string in){
    std::string kgram = in;
};


// Methods
void Kgram::print(){
    std::cout<< kgram << std::endl;
}

std::string Kgram::evolve(Distribution dist, int tot_char){
    std::cout <<"kgram in evolve is: " << kgram <<std::endl;
    // remove w1 and append c
    kgram.erase(0, 1);
    char c = dist.get_c(gen, kgram);
    //std::cout << c << std::endl;
    kgram += c;
    std::cout << kgram << std::endl;
    
    /*std::string temp;
    int counter = 0;
    while(kgram.size() < tot_char){
    // Look up the character distribution for w,and sample the next character c. 
    // repeat without removing w1
        temp = kgram[0];
        for (int i=0; i<counter; i++){
            temp += kgram[i];
        }
        std::cout << "t: " <<std::endl;
        kgram.erase(0, counter);//kgram.erase(0, 1);
        kgram = kgram + dist.get_c(gen, kgram);
        kgram.insert(0,temp);
        std::cout << kgram << std::endl;
        counter ++;
    }*/

    return kgram;

};