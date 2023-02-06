#include <iostream>

using namespace std;

class Count{
    private:
        int value;
    
    public:
        //costructor to initialize count to 5 
        Count(): value(5) {}

        //Overload ++ when used as prefix 
        void operator ++() {
            ++value;
        }

        void display(){
            cout << "Count: " << value << endl;
        }
};

int main(){

    Count count1;
    //call the "void operator ++ ()" function 
    ++count1;

    count1.display();

    return 0;
}