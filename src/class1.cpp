#include "class1.h"
#include <iostream>
#include "class2.h"
//#include "class2.cpp"

// Constructor
Kgram::Kgram(){
    string kgram;
    length = 0;
};

Kgram::Kgram(int length, Distribution dist){
    
    // Choose w_k- first character 
    random_device rd;
    mt19937 gen(rd());
    string kgram = dist.get_w(gen);
    cout << kgram << endl;
    string reduced_kgram = kgram.erase(0, 1);
    cout << reduced_kgram << endl;
    // Look up the character distribution for w, and sample the next character c. 
    //If alpha=0 and w has no transitions (it only occurs at the end of the training text), stop.

    // If len of k == length then exit else repeat above - implies while
    
    while(kgram.size()< length){
       

    }

}