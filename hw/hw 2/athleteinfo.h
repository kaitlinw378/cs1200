#include <string>

/*
The purpose of this is to create the class
Athlete which will be used to store and calculate
the information for each individual athlete in 
the olympics files. 
*/


class Athlete {
public:
    Athlete();
    Athlete(std::string first, std::string last, std::string place);



private: 
    std::string firstName; 
    std::string lastName;
    std::string country; 

    float hundredMeter; 
    float longJump;
    float shotPut; 
    float highJump;
    float fourHundred;
    float hurdles; 
    float discusThrow; 
    float poleVault;
    float javelin;
    float fifteenHundred; 

};