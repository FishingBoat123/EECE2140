#include "TV.h"

void TV::SetStation(int station) 
{
    if (station > 0 && station < 1000)
        itsStation = station;
    else
        cout << "Station number must be between 1 and 999." << endl;
}

int TV::GetStation() const
{
    return itsStation;
}

TV::TV() 
{
    SetStation(1);
} // default constructor

TV::TV(int station) // constructor that takes station as parameter
{
    SetStation(station);
}

void TV::display() 
{
    cout << "TV is on station " << GetStation() << endl;
}

void TV::channelUp()
{
    if (itsStation < 999)
        itsStation++;
    else
        cout << "Already at maximum station number." << endl;
}

void TV::channelDown()
{
    if (itsStation > 1)
        itsStation--;
    else
        cout << "Already at minimum station number." << endl;
}
