#include <iostream>

using namespace std;

/*
function overriding:
    Suppose, the same function is defined in both the derived class and
    the based class. Now if we call this function using the object of the
    derived class, the function of the derived class is executed.
*/

class Base{
    public:
        void print(){
            cout << "Base Function" << endl;
        }
};

class Derived : public Base{
    public:
        void print(){
            cout << "Derived Function" << endl;

            //call overridden function
            //Base::print()
        }
};

int main(){
    Derived derived1, derived2;
    derived1.print();
    /*to access the overriden function of the base class, we use 
    the scope resolution operator :: */
    derived2.Base::print();
    return 0;
}