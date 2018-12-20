#include<iostream>
//example of making function prototype
using namespace std;

int add(int a, int b);
int error();

int main(){
    cout << add(1, 2) << endl;
    //error(); will produce an error since it is not implemented
    return 0;
}

int add(int a, int b){
    return a + b;
}