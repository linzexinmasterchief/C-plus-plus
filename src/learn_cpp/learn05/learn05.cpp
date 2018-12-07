#include<iostream>
using namespace std;
//example of using multiple files to compile
//link the files while compiling using "clang learn05.cpp add.cpp -o learn05.exe"

int add(int a, int b);

int main(){
    cout << add(1, 2) << endl;
    return 0;
}