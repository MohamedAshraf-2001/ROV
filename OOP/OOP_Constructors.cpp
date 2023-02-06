#include <iostream>

using namespace std;

//A constructor is a special type of member function that is 
//called automatically when an object is created.

class Wall{

  private:
    double length;

public:
    //default constructor to initialize variable
    Wall(){

        length = 5.5;
        cout << "Creating a wall. " << endl;
        cout << "Length = " << length << endl;
    }
};

int main() {
    /*Here, when the wall1 object is created, the Wall() 
    constructor is called. This sets the length variable 
    of the object to 5.5.*/
    Wall wall1;
    return 0;
}