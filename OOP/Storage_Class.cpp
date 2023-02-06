#include <iostream>

using namespace std;

/*
Depending upon the storage class of a variable, it can be divided into 4 major types:

1) Local variable (automatic).
2) Global variable.
3) Static local variable.
4) Register Variable.
5) Thread Local Storage.
*/

/*
Local Variable
A variable defined inside a function (defined inside function 
body between braces) is  called a local variable or automatic variable.
Its scope is only limited to the function where it is defined.
 In simple terms, local variable exists and can be accessed only inside a function.

The life of a local variable ends (It is destroyed) when the function exits.
*/

/*
Global Variable
If a variable is defined outside all functions, then it is called a global variable.
The scope of a global variable is the whole program. This means, It can
be used and changed at any part of the program after its declaration.

Likewise, its life ends only when the program ends.
*/

/*
Static local variable 
exists only inside a function where it is declared (similar to a local 
variable) but its lifetime starts when the function is called and ends 
only when the program ends.
The main difference between local variable and static variable is that, the value of static variable persists the end of the program.
*/

void test();

//Global variable:
int x = 12;

int main(){

test();

test();

test();

    return 0;
}

void test(){
    //static vaiable:
    static int stat_var = 0;
    //Local variable to test:
    int loc_var = 6;
    ++loc_var;
    ++stat_var;
    ++x;
    cout << "static variable: " << stat_var << '\t' << "local variable: " << loc_var << '\t' << "Global variable: " << x << endl;
}


/*
Keyword register is used for specifying register variables.

Register variables are similar to automatic variables and exists inside 
a particular function only. It is supposed to be faster than the local 
variables. If a program encounters a register variable, it stores the variable
 in processor's register rather than memory if available. This makes it faster 
 than the local variables.
*/

/*
Thread Local Storage

Thread-local storage is a mechanism by which variables are allocated
such that there is one instance of the variable per extant thread. Keyword 
thread_local is used for this purpose.

Learn more about thread local storage.
*/