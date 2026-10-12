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
    // Get file as a string
    string text = Read(filename);

    // Then go through each k-gram and record its weightings
    string kgram;

    for (int i=0; i < (text.length() - k); i++){
        // empty the kgram
        kgram = "";

        //Generate a temporary string represting the k-gram: via text[i]+text[1+1]...+text[i+k];
        for (int j=0; j <k; j++){
            kgram += text[i+j];
        }

        // Record this kgram's frequency in the distribution

    }
};