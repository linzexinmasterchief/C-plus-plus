#include<iostream>

//using void function
using namespace std;
void get_void(){
    //error
    #warning return type void: dont return anything
    //return 0;
}

int main(){
    //error
    #warning a value of type "void" cannot be used to initialize an entity of type "int"
    // int a = get_void();
    
    //the code should have no output
    return 0;
}