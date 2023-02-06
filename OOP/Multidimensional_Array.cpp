#include <iostream>

using namespace std; 

int main(){

//for two dimensional array ==> array[row][column].
int test[3][2] = {{1,2},
                  {3,4},
                  {5,6}};

    //access rows:    
for (int i = 0; i<3; ++i){
    //access columns:
    for (int j = 0; j < 2; ++j){
       cout << "test[" << i << "][" << j << "] = " << test[i][j] << endl;
        }
    }

    return 0;
}