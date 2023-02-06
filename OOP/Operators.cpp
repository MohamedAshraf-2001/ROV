#include <iostream>

using namespace std;

int main(){

//C++ Arithmetic Operators:
int a, b;
a = 10;
b = 2;

cout << "a + b =" << (a + b) << endl;
cout << "a - b =" << (a - b) << endl;
cout << "a * b =" << (a * b) << endl;
cout << "a / b =" << (a / b) << endl;
cout << "a % b = " << (a % b) << endl;
cout << "a % 3 =" << (a % 3) << endl;
//assigned new value to variable a.
cout << "a += b ==> a = a + b: " << (a+=b) << endl;

cout << '\n' << endl;
cout << "size of a =  " << sizeof(a) << endl;

//Bitwise Operators:
// These operators are necessary because the ALU present 
// in the computer's CPU carries out arthimetic at the bit-levlel. 
int x = 12;      //00001100 (Binary).
int y = 25;      //00011001 (Binary).

//Bitwise AND
cout << "x & y = " << (x & y) << endl; //8 (decimal) 00001000 (binary).
//Bitwise OR
cout << "x | y = " << (x | y) << endl; //29 (decimal) 00011101 (binary).
//Bitwise XOR
cout << "x ^ y = " << (x ^ y) << endl; //21 (decimal) 00010101 (binary).

    return 0;
}