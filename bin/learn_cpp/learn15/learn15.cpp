#include<iostream>

//the output of boolean variables
using namespace std;
int main(){
    bool b(false);
    cout << b << endl; // b is false, which evaluates to 0
    cout << !b << endl; // !b is true, which evaluates to 1

    cout << boolalpha; // change output to false/true

    cout << b << endl; // b is false
    cout << !b << endl; // !b is true

    return 0;
}