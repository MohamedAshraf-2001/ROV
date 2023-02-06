#include <iostream>

using namespace std;


/*
Structure is a collection of variables of different data types under 
a single name. it is similar to a class in that, both holds a collection
of data of differenct data types.
*/


//define struct 
struct Person{
    char name[50];
    int age;
    float salary;
};

int main(){

    Person p_1;

    cout << "Enter Full name: ";
    cin.get(p_1.name, 50);
    cout << "Enter age: ";
    cin >> p_1.age;
    cout << "Enter salary: ";
    cin >> p_1.salary;

    cout << "\nInformation Displaying. " << endl;
    cout << "Name: " << p_1.name << endl;
    cout << "Age: " << p_1.age << endl;
    cout << "Salary: " << p_1.salary;

    return 0;
}

/*
Here a structure Person is declared which has three members name, age and salary.
Inside main() function, a structure variable p1 is defined. Then, 
the user is asked to enter information and data entered by user is displayed.
*/