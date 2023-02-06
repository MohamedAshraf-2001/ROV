#include <iostream>

using namespace std;

/*there is a feature in C++ called friend function that break the rule 
of data hiding and allow us to access member functions from outside class*/

class Distance{
    private:
        int meter;

        //friend function 
        friend int addFive(Distance);

    public:
        Distance() : meter(0) {}
};

//friend function 
int addFive(Distance d){
    d.meter += 5;
    return d.meter;
}

int main(){

    Distance D;
    cout << "Distance: " << addFive(D);
    return 0;
}