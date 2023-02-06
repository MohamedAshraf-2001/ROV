#include <iostream>

using namespace std;

/*a virtual function is a member function in the base class 
that we expect to redefine in derived classes
Basically, a virtual function is used in the base class in 
order to ensure that the function is overridden. This especially
 applies to cases where a pointer of base class points to an object 
 of a derived class.*/

class Base{
    public:
        virtual void print(){
            cout << "Base Function" << endl;
        }
}; 

class Derived : public Base{
    public:
        void print(){
            cout << "Drived Function" << endl;
        }
};

int main(){

    Derived derived1;

    //pointer of Base type that points to derived1
    Base* base1 = &derived1;

    //calls member function of derived class
    base1->print();

    return 0;
}