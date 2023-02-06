#include <iostream>

using namespace std;

/* 
There are two types of function:

1) Standard Library Functions: Predefined in C++.
2) User-defined Function: Created by users.

C++ Function Declaration:

returnType function_name (param#1, param#2, .....){
        function body
}
*/

/*Function Prototype
In C++, the code of function declaration should be before the function call. 
However, if we want to define a function after the function call,
 we need to use the function prototype*/

//Function prototype:
void greet();

int add(int , int );

int main(){

greet();

int x, y;
cout << "Enter the fisrt number: ";
cin >> x;
cout << "Enter the second number: ";
cin >> y;

cout << "The result is: " << add(x,y); 
    return 0;
}

//Function definition:
void greet(){
    cout << "Hello user\n";
}

int add(int a, int b){
    return (a + b);
}