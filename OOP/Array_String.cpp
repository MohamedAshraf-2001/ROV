#include <iostream>

using namespace std;

int main(){

char str[] = {'C', '+', '+'};
cout << str << endl;

char new_str[100];

//the extraction operator >> works as scanf() in C and 
//considers a space " " has a terminating character.
cout << "Enter a string: ";
cin >> new_str;
cout << "The string: " << new_str << endl;
cout << "Enter another string: ";
cin >> new_str;
cout << "New The string: " << new_str << endl;
    return 0;
}