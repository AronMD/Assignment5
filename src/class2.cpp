#include "class2.h"
#include <iostream>
#include <fstream>
#include <map>
#include <random>

//using namespace std;




// private methods
std::string Distribution::Read(std::string filename){
    // generate required variables
    std::ifstream in;
    std::string s;
    std::string text;

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




std::map<std::string, int> Distribution::Map_Gen(std::string text, int k){
    std::string kgram;
    std::map<std::string, int> store;

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
    /*vector<string> names;
    vector<int> weights;
    discrete_distribution<> dist;*/
};

// Others
Distribution::Distribution(std::string filename, int k, float alpha){
    /*vector<string> names;
    vector<int> weights;
    discrete_distribution<> dist;*/

    // Get file as a string
    std::string text = Read(filename);

    // Then go through each k-gram and record its weightings
    std::map<std::string, int> store = Map_Gen(text, k);

    // Convert to a distribution of initial k-grams to return
    // iterate part by part vector of kgrams and then vector of weightings which becomes distribution

    for (auto& pair : store){
        //cout << pair.first << " " <<pair.second << endl;
        names.push_back(pair.first);
        weights.push_back(pair.second);
    }

    // need names to be sent out
    dist = std::discrete_distribution<> (weights.begin(), weights.end());
};

// Methods:
std::string Distribution::get_w(std::mt19937 gen){
    //random_device rd;
    //mt19937 gen(rd());
    int random_index = dist(gen);
    //cout << random_index << endl;
    std::string selected_string = names[random_index];

    return selected_string;
};




void Distribution::print(){
    for (auto kgram : names){
        std::cout << kgram << std::endl;
    }
};
// need one for selecting for P(c|w)

// need one for alpha

//