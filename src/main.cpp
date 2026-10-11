#include "class1.h"
#include "class2.h"
#include <iostream>
#include <unistd.h>

int main(int argc, char *argv[]){
    
    // Get command line arguments for -a
    int opt;
    while((opt = getopt(argc, argv, “:if:lrx”)) != -1) 
    { 
        switch(opt) 
        { 
            case 'a': 
                printf("option: %c\n", optarg);
                break; 

        } 
    } 
    for(; optind < argc; optind++){     
        printf("extra arguments: %s\n", argv[optind]); 
    }




    return 0;
}