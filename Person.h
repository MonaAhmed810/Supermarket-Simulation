#ifndef PERSON_H
#define PERSON_H

#include <iostream>

using namespace std;

class Person
{
protected:
    string name ;
    string adress;
public:
    Person();
    virtual ~Person();
    string getName() const ;
    string getAdress() const;
    void setName(string );
    void setAdress(string );

};

#endif // PERSON_H
