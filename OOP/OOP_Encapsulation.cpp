#include <iostream>

using namespace std;

/*
Encapsulation is one of the key features of OOP. it involves the bundling 
of data members and functions inside a single class.

Bundling similar data members and functions inside a class together also 
helps in data hiding. 
*/

class Rectangle{
   public: 
    //Variables required for area calculation
    int length;
    int breadth;

    //constructor to initialize variables 
    Rectangle(int len, int brth): length(len), breadth(brth) {}

    //Function to calculate area
    int getArea(){
        return length * breadth;
    }
};

int main(){
    //create object of rectangle class
    Rectangle rect(8, 6);

    //call getArea() function
    cout << "Area = " << rect.getArea();
return 0;
}