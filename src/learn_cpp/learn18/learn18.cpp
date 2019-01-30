#include<iostream>
using namespace std;

int main(){
    int x = 5;
    int y = 7;
 
    if (! x == y)
        cout << "x does not equal y" << endl;
    else
        cout << "x equals y" << endl;
        //x equals y outputed
        //This program prints “x equals y”! But x does not equal y, so how is this possible? 
        //The answer is that because the logical NOT operator has higher precedence than the 
        //equality operator, the expression ! x == y actually evaluates as (!x) == y. 
        //Since x is 5, !x evaluates to 0, and 0 == y is false, so the else statement executes!
        //use "if (!(x == y))" to achieve the target
    
    x = 2;
    if (x == 1 && y++ == 2){
        //since either part of && operator being false will result in the final result to be false
        //if x == 1 is false, there is no need to compare y++ with 2, therefore, y++ will not be 
        //executed.
    }
    cout << "y = " << y << endl;
    //when x is 1, y will be 8
    //      other,           7
    return 0;
}