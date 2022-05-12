#include <iostream> 
#include <vector> 
#include <fstream>

#include "athleteinfo.h" 

/* 

The purpose of this program is to run the athleteinfo 
class and athlete.h file.

*/

int main(int argc, char *argv[]){

    std::ifstream file (argv[1]); 
    std::string current; 
    std::string currentEvent; 

    if (!file.isGood()){
        std:cerr << "File cannot be opened";
        return 1;
    }

    while (file >> current){
        if current == "event"{
            file >> currentEvent; 
        }
        else {
            std::string tempFirstName; 
            std::string tempLastName; 
            std::string tempCountry;
            float tempScore; 


        }
    }
}