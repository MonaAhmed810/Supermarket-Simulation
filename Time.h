#ifndef TIME_H
#define TIME_H

#include <iostream>

using namespace std;

class Time
{
private:
    int hour,minute;
public:
    Time();
    void setHour(int h) ;
    void setMinute(int m);
    int getHour() const ;
    int getMinute() const ;
    Time operator+(const Time&);
    bool operator>(const Time&);
    bool operator==(const Time&);
    bool operator<=(const Time&);

};

#endif // TIME_H
