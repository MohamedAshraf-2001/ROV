#include <iostream>
#include <cmath>

using namespace std;

//Base Class
class Polygon {

    protected:

        //dimension ==> width of one side.
        float dimension;
        
    public:

        void getDimension(){
            cin >> dimension;
        }

        virtual float calculateArea() = 0;
        virtual float calculatePerimeter() = 0;
        virtual void Draw() = 0;
};

//Derived Classes

class Square : public Polygon {
   public:
    float calculateArea() {
        return dimension * dimension;
    }

    float calculatePerimeter(){
        return 4 * dimension;
    }

    void Draw(){
        for (int i = 1; i <= dimension ; i++){
            for (int j = 1; j <= dimension ; j++)
                cout << " * ";
        cout << endl;
        }
    }
};

class Triangle : public Polygon{
    public:
        float calculateArea() {
            return (sqrt(3)/4) * dimension * dimension;
        }

        float calculatePerimeter(){
            return 1.5 * dimension;
        }

        void Draw(){
        for(int i = dimension; i >= 1; --i){
            for(int j = 1; j <= i; ++j)
                {
                cout << j << " ";
                }
            cout << endl;
        }
    }
};

class Hexagon : public Polygon{
    public:
     
        int a;
        float calculateArea() {
            a = dimension / (2 * tan(30));
            return 0.5 * a * dimension;
        }

        float calculatePerimeter(){
            return 6 * dimension;
        }

        void Draw(){
         for(int i = 0, k = dimension, l = 2 * dimension - 1; i < dimension; ++i, --k, ++l){

            for(int j = 0; j < 3 * dimension; ++j)
            {
             if(j >= k && j <= l)
            cout << "*";
            else
            cout << " ";
            }
            cout << endl;
        }
    
        for(int i = 0; i < dimension; ++i){
            for(int j = 0; j < 3*dimension; ++j)
            cout << "*";
            cout << endl;
        }
    
        for(int i = 0, k = 1, l = 3 * dimension - 2; i < dimension; ++i, ++k, --l){
            for(int j = 0; j < 3 * dimension; ++j)
            {
                if(j >= k && j <= l)
                cout << "*";
                else
                cout << " ";
            }
            cout << endl;
        }
        }

};



int main(){

    Square square;
    Triangle triangle;
    Hexagon hexagon;
    //ID ==> Shape.
    //option ==> Type of Calculation.
    int ID, option;

    cout << "-Availabe Shapes: " << endl;
    cout << "1) Square. \n2) Triangle \n3) Hexagon"<< endl;
    cout << "Select ID Num of The Shape: " << endl;

    cin >> ID;

    cout << "Enter the Dimension" << endl;
    if (ID == 1){
        square.getDimension();
    }
    else if (ID == 2){
        triangle.getDimension();
    }
    else {
        hexagon.getDimension();
    }

    cout << "Select an Option to Compute one feature of Your Shape: " << endl;
    cout << "1) Area. \n2) perimeter. \n3) Draw." << endl;

    cin >> option;

    switch(ID) {

        case 1: 
         
         switch(option) {
            case 1:
                cout << square.calculateArea() << endl;
                break;
            case 2:
                cout << square.calculatePerimeter() << endl;
                break;
            case 3:
               square.Draw();
               break;
         }
            break;

        case 2: 
          
          switch(option)
            {
            case 1:
                cout << triangle.calculateArea() << endl;
                break;
            case 2:
                cout << triangle.calculatePerimeter() << endl;
                break;
            case 3:
               triangle.Draw();
               break;
            }
            break;

        case 3: 
         
         switch(option)
            {
            case 1:
                cout << hexagon.calculateArea() << endl;
                break;
            case 2:
                cout << hexagon.calculatePerimeter() << endl;
                break;
            case 3:
               hexagon.Draw();
               break;
            }
            break;

        default:
            cout << "ERROR Event";
            break; 
    }

    return 0;
}