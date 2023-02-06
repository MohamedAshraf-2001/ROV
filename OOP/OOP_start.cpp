/*
-We can think of a class as a sketch (prototype) of a house. 
It contains all the details about the floors, doors, windows, etc. 
Based on these descriptions we build the house. House is the object.

-we can access the data members and member functions of a class by 
using a '.' (dot) operator.

-public ==> This means the members are public and 
can be accessed anywhere from the program.

-private ==> The private members of a class can only be 
accessed from within the class. 
*/

#include <iostream>

using namespace std;

//create a class:
class Room{

    public:
        double length;
        double breadth;
        double height;

        double calculateArea(){
            return length * breadth;
        }

        double calculateVolume(){
            return length * breadth * height;
        }
};

int main() {

    //create object of room class
    Room room1;

    //assign values to data members
    room1.length = 42.5;
    room1.breadth = 30.8;
    room1.height = 19.2;

    //calculate and display the area and volume of the room 
    cout << "Area of room = " << room1.calculateArea() << endl;
    cout << "Volume of room = " << room1.calculateVolume() << endl;

    return 0;
}