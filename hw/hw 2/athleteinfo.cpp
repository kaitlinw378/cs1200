#include <iostream> 
#include "athleteinfo.h" 

/*

The purpose of this program is to run the athlete 
info class and do the calculations and store the 
information for each individual athlete. 

*/

Athlete::Athlete() {

    std::string firstName = ""; 
    std::string lastName = "";
    std::string country = ""; 

    float hundredMeter = 0; 
    float longJump = 0;
    float shotPut = 0; 
    float highJump = 0;
    float fourHundred = 0;
    float hurdles = 0; 
    float discusThrow = 0; 
    float poleVault = 0;
    float javelin = 0;
    float fifteenHundred = 0; 


}

Athlete::Athlete(std::string first, std::string last, std::string place){
    std::string firstName = first; 
    std::string lastName = last;
    std::string country = place; 

    float hundredMeter = 0; 
    float longJump = 0;
    float shotPut = 0; 
    float highJump = 0;
    float fourHundred = 0;
    float hurdles = 0; 
    float discusThrow = 0; 
    float poleVault = 0;
    float javelin = 0;
    float fifteenHundred = 0; 
}


