#ifndef TV_H
#define TV_H

#include <iostream>
using namespace std;

class TV
{
private: 
    int itsStation;

public:
    void SetStation(int station);
    int GetStation() const;

    TV(); 
    TV(int station);

    void display(); 
    void channelUp();
    void channelDown();
};

#endif
