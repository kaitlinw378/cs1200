class Time { 
public:
    Time();
    Time(int aHour, int aMin, int aSec);

    int getHour() const {return Hour;}
    int getMinute() const; 
    int getSecond() const;

    int PrintAMPM() const;

    void setHour(int h) ; 
    void setMinute(int h) ;
    void setSecond(int h); 

private: 
    int Hour;
    int Min;
    int Sec;

};