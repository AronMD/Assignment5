#include "class1.h"
#include "class2.h"
#include <iostream>
#include <unistd.h>

int main(int argc, char *argv[]){
    
    // Get command line arguments for -a
    int opt;
    int errflg;
    char *ifile;
    char *pre_alpha;
    float alpha = 0;

    while((opt = getopt(argc, argv, ":f:a:")) != -1){ 
        switch(opt){ 
        case 'f':
            ifile = optarg;
            break;
        case 'a':
            pre_alpha = optarg;
            alpha = atof(pre_alpha);
            
            break;
            case ':':       /* -f or -o without operand */
                    fprintf(stderr,
                            "Option -%c requires an operand\n", optopt);
                    errflg++;
                    break;
        } 
    }

    cout << "alpha is: " << alpha<< endl;


    for(; optind < argc; optind++){     
        printf("extra arguments: %s\n", argv[optind]); 

        // Then divide up extra args into appropriate order
    }




    return 0;
}