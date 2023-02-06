#include <iostream>

using namespace std;

class Student {
    public:
        double marks1, marks2;
};

//function that returns object of Student 
Student createStudent(){

    Student student;

    //initialize member variable of student 
    student.marks1 = 96.5;
    student.marks2 = 75.0;

    //print member variables of Student 
    cout << "Marks 1 = " << student.marks1 << endl;
    cout << "Marks 2 = " << student.marks2 << endl;

    return student;
}

/*In this program, we have created a function createStudent() that returns an object of Student class.
We have called createStudent() from the main() method.*/

int main(){

    Student student1;

    student1 = createStudent();

    return 0;
}