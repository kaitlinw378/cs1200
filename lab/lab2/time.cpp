#include <iostream> 
#include "time.h" 


int Time::getMinute() const{
    return Min;
}

int Time::getSecond() const{
    return Sec;
}

int Time::PrintAMPM() const{
    if (Hour > 12){ 
        int temp = Hour - 12; 
    
        std::cout << "a: " << temp << ":" ; 
        if (min < 10){
           std::cout << "0" << Min;
        } 
        else
            std::cout << Min 
        std::cout << ":" << Sec << " pm " << std::endl;
        }else{
        std::cout << "a: " << Hour << ":" <<  Min << ":" << Sec << " am " << std::endl;
    }


}

void Time::setHour(int h) {
    Hour = h;
}

void Time::setMinute(int h) {
    Min = h;
}

void Time::setSecond(int h) {
    Sec = h;
}

Time::Time(){
    Hour = 0;
    Min = 0;
    Sec = 0;
}

Time::Time(int aHour, int aMin, int aSec){
    Hour = aHour;
    Min = aMin;
    Sec = aSec;
}
