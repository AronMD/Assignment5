#include <iostream>
#include <unistd.h>
#include <map>
#include <random>
#include "class1.h"
#include "class2.cpp"
#include "class2.h"


using namespace std;


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
        } 
    }
    // ensure alpha >= 0
    if (alpha < 0)
        throw invalid_argument("alpha provided must be greater than or equal to 0");
    
    // Ensures enough arguments passed
    if (argv[optind] == NULL || argv[optind + 1] == NULL || argv[optind + 2] == NULL)
    throw invalid_argument("three arguments are required \n[int k] [trainingfile.txt] [int total characters] \nnote total characters must be greater or equal to k");

    // read arguments
    k = stoi(string(argv[optind]));
    filename = argv[optind + 1];
    tot_char = stoi(string(argv[optind + 2]));


    cout << "alpha is: " << alpha<< endl;
    cout <<"k = " << k << endl;
    cout <<"training file is: " << filename << endl;
    cout <<"length of generated characters = " << tot_char << endl;


    // search file character by character and record values to generate distribution
    Distribution dist = Distribution(filename, k, alpha);

    cout << dist.get_w();










    return 0;
}