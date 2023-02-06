#include <iostream>

using namespace std;

class Room{

    private:
        double length;
        double breadth;
        double height;

    //functions to initialize private variables 
    public:
        void initData(double len, double brth, double hgt){
            length = len;
            breadth = brth;
            height = hgt;
        }
    
        double calculateArea(){
            return length * breadth;
        }

        double calculateVolume(){
            return length * breadth * height;
        }

};


int main() {

    //create object of Room class
    Room room1;

    //pass the values of private variables as arguments
    room1.initData(42.5, 30.8, 19.2);

    cout << "The area of Room = " << room1.calculateArea() << endl;
    cout << "The area of Room = " << room1.calculateVolume() << endl;
}