#include "TV.h"

int main()
{
    TV myTV;
    //myTV.itsStation = 9; // this is wrong, cant acess private from outside of class. fix is to use the set station method.
    //TV.setStation(10); // this is wrong, should be myTV.setStation(10). fix is to use the object name to call the method.
    //TV myOtherTV(2); // this is wrong, TV does not have a constructor that takes an int parameter. 


    //fix:
    myTV.SetStation(9); // set station to 9 using the setter method
    TV myOtherTV(2); // create a myOtherTV with station 2 using the constructor

    myTV.display();
    myTV.channelUp();
    myTV.display();
    cout << "Other TV is on station " << myOtherTV.GetStation() << endl;
}
