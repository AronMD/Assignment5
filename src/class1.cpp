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
    //std::cout << "kgram in the constructor: " << kgram << std::endl;
};


Kgram::Kgram(std::string in){
    std::string kgram = in;
};


// Methods
void Kgram::print(){
    std::cout<< kgram << std::endl;
}



bool Kgram::test(std::string text){

    // make text something one can get from dist.text() and then can just shove in here

    int loc = text.size() - kgram.size();
    if (kgram == text.substr(loc)){
        // the string here is the end of the training text and thus terminating
        return true;
    }
    else {
        return false;
    }
};


std::string Kgram::evolve(Distribution dist, int tot_char){
    // remove w1 and append c
    std::cout << kgram << std::endl;
    kgram.erase(0, 1);
    char c = dist.get_c(gen, kgram);
    //std::cout << c << std::endl;
    kgram += c;
    std::cout << kgram << std::endl;


    int counter = 1;
    std::string temp;
    while(kgram.size() < tot_char){

        temp = kgram.substr(0, counter);

        kgram.erase(0, counter);
        char c = dist.get_c(gen, kgram);
        //std::cout << c << std::endl;
        kgram += c;
        kgram.insert(0, temp);
        //std::cout << kgram << std::endl;
        counter++;

        if (counter == 10000){
            break;
        }
    }

    return kgram;
};


std::string Kgram::evolve_alpha(Distribution dist, int tot_char, float alpha){
    // remove w1 and append c
    kgram.erase(0, 1);
    char c = dist.get_c_alpha(gen, kgram, alpha);
    kgram += c;

    // Evolve but with alpha
    int counter = 1;
    std::string temp;
    while(kgram.size() < tot_char){
        temp = kgram.substr(0, counter);
        kgram.erase(0, counter);
        char c = dist.get_c_alpha(gen, kgram, alpha);
        kgram += c;
        kgram.insert(0, temp);
        counter++;

        if (counter == 10000){
            break;
        }
    }

    return kgram;
};