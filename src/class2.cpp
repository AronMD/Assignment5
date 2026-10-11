#include "class2.h"
#include <iostream>
#include <fstream>


using namespace std;
// private methods
string Read(string filename){
    ifstream in;
    string s;
    string text;

    in.open(filename);
        while (getline(in ,s)) {
            text += s;
        };  

    //close file
    in.close();

    return text;
}


// Constructors
Distribution::Distribution(){
    // Generate a uniform one with alpha = 0
};

Distribution::Distribution(string filename, int k){
    string text = ;
    for (int i=0; i < (text.length() - k); i++){
                
    }
};


