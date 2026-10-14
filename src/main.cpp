#include <iostream>
#include <unistd.h>
#include <map>
#include <random>
#include "class2.cpp"
#include "class2.h"
#include "class1.h"
#include "class1.cpp"


using namespace std;

/*
To DO:
w has no transitions (it only occurs at the end of the training text), stop.
alpha
makefile

*/

void error_check(int k, string filename, int tot_char){
    // a k or an output length that is not a positive integer, or an output length smaller than k
    if ((k <= 1) or (k > tot_char))
        throw domain_error("k must be greater 1 and must be smaller or equal to the final outputted number of characters");

    //a training file that cannot be opened
    ifstream file;
    file.open(filename);
    if (!file.is_open())
        throw invalid_argument("Training file not detected");
    file.close();

};




void error_alpha(string pre_alpha, float alpha){
    // ensure alpha given isnt a string - atof returns 0 if it is, need to check alpha hasnt been specified as 0 or 0.00
    if ((alpha == 0) and ( pre_alpha[0] != '0'))
        throw invalid_argument("alpha is a number greater than or equal to 0");
};




int main(int argc, char *argv[]){
    // initalise variables 
    float alpha = 0;
    int k;
    string filename;
    int tot_char;

    // below should likely be its own function returns array with answers? rather than memory address stuff
    
    // Get command line arguments for -a
    int opt;
    char *pre_alpha;

    while((opt = getopt(argc, argv, "::a:")) != -1){ 
        switch(opt){ 
        case 'a':
            pre_alpha = optarg;
            alpha = atof(pre_alpha);
            error_alpha(pre_alpha, alpha);
            }
            
        } 
    
    // ensure alpha >= 0
    if (alpha < 0)
        throw domain_error("alpha provided must be greater than or equal to 0");
    
    // Ensures enough arguments passed
    if (argv[optind] == NULL || argv[optind + 1] == NULL || argv[optind + 2] == NULL)
    throw invalid_argument("three arguments are required \n[int k] [trainingfile.txt] [int total characters] \nnote total characters must be greater or equal to k");

    // read arguments
    k = stoi(string(argv[optind]));
    filename = argv[optind + 1];
    tot_char = stoi(string(argv[optind + 2]));

    error_check(k, filename, tot_char);

    cout << "alpha is: " << alpha<< endl;
    cout <<"k = " << k << endl;
    cout <<"training file is: " << filename << endl;
    cout <<"length of generated characters = " << tot_char << "\n" << endl;

    // search file character by character and record values to generate distribution
    Distribution dist(filename, k, alpha);
    vector<string> names = dist.names;

    // random seed generation
    random_device rd;
    mt19937 gen(rd());

    // deciding to evolve the kgram either with alpha or not
    if (alpha != 0){
        Kgram kgr(dist, gen);
        cout << "The generated text is: " << endl;
        // Evolve alpha
        kgr.evolve_alpha(dist, tot_char, alpha);
        kgr.print();
    }
    else{
        // Generate the kgram and then evolve it longer
        Kgram kgr(dist, gen);
        cout << "The generated text is: " << endl;
        kgr.evolve(dist, tot_char);
        kgr.print();
    }

    return 0;
}