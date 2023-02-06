#include <iostream>

using namespace std;


// C++ Array Declaration:
//dataType arrayName[arraySize];


int main(){
int i;
//in C++, it's possible to initialize an array during 
//declaration:
int x[6] = {1,2,3,4,5,6};  //Size is 6 elements

//Here, we have not mentioned the size of the array.
//in such cases, the compiler automatically computes the size.
int y[] = {7,8,9,10,11};

//Empty array memebers are automatically assigned the value 0.

//Displaying Array Elements:
int numbers[5] = {1,2,3,4,10};
//Traditional loop ==> not preferred 
cout << "By Traditional loop: " << endl;
cout << "The numbers of the array: " << endl;
for (i=0; i < 5; ++i){
    cout << numbers[i] << '\n';
}

//range based-loop: 

//1) Using int n simply copies the array elements to the variable n 
//during each iteration. This is not memory-efficient.

//2) &n, however, uses the memory address of the array elements to
// access thier data without copying them to a new variable. 
// This is memory-efficient.
cout << "Based-range loop: " << endl;
for (const int  &n: numbers){
    cout << n << '\n' ; 
}

    return 0;
}