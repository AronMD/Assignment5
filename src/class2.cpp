#include "class2.h"
#include <iostream>
#include <fstream>
#include <map>

using namespace std;




// private methods
string Read(string filename){
    // generate required variables
    ifstream in;
    string s;
    string text;

    // Open file
    in.open(filename);
    
    // form a single string for the whole text file
    while (getline(in, s)) {
        text += s;
    };  

    //close file
    in.close();

    return text;
}




map<string, int> Map_Gen(string text, int k){
    string kgram;
    map<string, int> store;

    for (int i=0; i < (text.length() - k + 1); i++){
        // empty the kgram
        kgram = "";

        //Generate a temporary string represting the k-gram: via text[i]+text[1+1]...+text[i+k];
        for (int j=0; j <k; j++){
            kgram += text[i+j];
        }

        // Recording this kgram's frequency in a map
        // Finding element with key kgram
        auto it = store.find(kgram);
        if (it != store.end()){
            // update element weighting with +1
            store.at(kgram)++;
        }
        else {
            // append new pair with weight 1
            store.insert({kgram, 1});
        }
    }
    return store;
}






// Constructors
// Default
Distribution::Distribution(){
    // Generate a uniform one with alpha = 0 for 0 elements
};

// Others
Distribution::Distribution(string filename, int k, float alpha){
    // Get file as a string
    string text = Read(filename);

    // Then go through each k-gram and record its weightings
    map<string, int> store = Map_Gen(text, k);

    // Convert to a distribution to return with alpha included
    



};

// Methods:

// need one for selecting for P(c|w)