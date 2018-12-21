#include<iostream>

//using constant and constexpr
void redefine_x();
constexpr int sqr(int arg);

using namespace std;

int main(){
    #define x 10
    //int x = 1; after #define x will pop out an error "expect a variable"

    const int a = 1;
    //a = 2; const can't be changed

    cout << "macro x is " << x << endl; //10
    #define x 1 //executed
    redefine_x();
    cout << "x is now " << x << endl; //1

    static constexpr int N = 3;
    constexpr const int *NP = &N; //constexpr states *NP is a constant expression
    //const states that the pointer is pointing to a constant

    cout << "square of " << N << " is " << sqr(N) << endl;
    cout << "the address of " << N << " is " << NP << endl;

    return 0;
}

void redefine_x(){
    //not executed
    #define x 9 //redefined x to 9, since #define is in file scope
}

//only functions with constexpr could take constant parameters
constexpr int sqr(int arg){
    return arg*arg;
}

//Avoid using #define to create symbolic constants