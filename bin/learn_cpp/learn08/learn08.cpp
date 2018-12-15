#include<iostream>
using namespace std;

//example of different ways of variable initialization
int main(){
    //copy assignment
    int i;
    i = 0;

    //uniform initialization
    //65 is the ascii code for A
    char c{65};

    //copy initialization
    bool b = 0;

    //direct initialization
    float f(0);

    //initializing multiple variables
    double d1 = 0, d2 = 1;
    // int d1(0), d2(1);
    // int d1{0}, d2{1};

    // int a, int b; // wrong (compiler error)
    // int a, b; // correct

    int x, y(5); // only initialized y

    cout << "int i = " << i << endl;
    cout << "char c = " << c << endl;
    cout << "bool b = " << b << endl;
    cout << "float f = " << f << endl;
    cout << "double d1 = " << d1 << ", d2 = " << d2 << endl;
    cout << "x is not initialized: " << x << ", y is initialized: " << y << endl;

    return 0;
}