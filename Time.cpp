#include "Time.h"

#include <iostream>

using namespace std;

Time::Time()
{
    //ctor
}
Time Time::operator+(const Time& obj)
{
    Time temp;
    int h=hour+obj.hour,m=minute+obj.minute;
    if(m>=60)
    {
        h++;
        m-=60;
    }
    temp.setHour(h);
    temp.setMinute(m);
    return temp;
}
bool Time::operator>(const Time &c2)
{
    int x = hour*60+minute;
    int y = c2.hour*60+c2.minute;
    return (x>y);
}
bool Time::operator==(const Time &c2)
{
    int x = hour*60+minute;
    int y = c2.hour*60+c2.minute;
    return (x==y);
}
bool Time::operator<=(const Time &c2)
{
    int x = hour*60+minute;
    int y = c2.hour*60+c2.minute;
    return (x<=y);
}
void  Time::setHour(int h)
{
    hour = h ;
}
void  Time::setMinute(int m)
{
    minute = m ;
}
int  Time::getHour() const
{
    return hour ;
}
int  Time::getMinute() const
{
    return minute ;
}
