#include <iostream>

using namespace std;


int main(){
//C++ Implicit Conversion:
//The type conversion that is done automatically done
//by the compiler is known as implicit type conversion.
//This type of conversion is also known as automatic conversion.
int x = 1;
double num;
num = x;
cout << "Implicit conversion: " << num;

//C++ Explicit Conversion:
// 1) C-style type casting (cast notation).
int num_int = 9;
double num_double;
num_double = (double)num_int;       //(data_type)expression;
cout << "1) C-style type casting (cast notation)" << num_double;
// 2) Function notation (old C++ style type casting).
int a_int = 26;
double a_double;
a_double = int(a_int);    //data_type(expression);
cout << "Function notation (old C++ style type casting)" << a_double;
// 3) Type conversion operators

    return 0;
}