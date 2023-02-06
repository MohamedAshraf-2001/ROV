#include <iostream>

using namespace std;

class Wall {

    private:
        double length;
        double height;

    public:
        Wall(double len, double hgt){
            length= len;
            height = hgt;
        }

        //copy constructor with a Wall object as a parameter 
        //copies data of the obj parameter
        Wall(Wall &obj){
            length = obj.length;
            height = obj.height;
        } //&obj = &wall1
        
        //Notice that the parameter of this constructor has the address of an object of the Wall class.
        //We then assign the values of the variables of the obj object to the corresponding variables of 
        //the object calling the copy constructor. This is how the contents of the object are copied.

        double calculateArea(){
            return length * height;
        }
};

int main(){

    //create an object of Wall class
    Wall wall1(10.5, 8.6);

    //copy contents of wall1 to wall2
    Wall wall2 = wall1;

    cout << "Area of Wall 1: " << wall1.calculateArea() << endl;
    cout << "Area of Wall 2: " << wall2.calculateArea();

    return 0;
}