#include<iostream>
//example of making forward declarations (function prototype)
using namespace std;

int add(int a, int b);

int main(){
    cout << add(1, 2) << endl;
    return 0;
}

int add(int a, int b){
    return a + b;
}