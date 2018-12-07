#include<iostream>

//created a function
void print(const int &x){
    std::cout << x << std::endl;
}

int main(){
    int x = 3;
    print(x);
    return 0;
}