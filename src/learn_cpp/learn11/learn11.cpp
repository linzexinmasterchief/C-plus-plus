#include<iostream>

using namespace std;
int main(){
    //examples of different types of integer definition

    // char c;
    // short int si; // valid
    // short s;      // preferred
    // int i;
    // long int li; // valid
    // long l;      // preferred
    // long long int lli; // valid
    // long long ll;      // preferred

    // signed char c;
    // signed short s;
    // signed int i;
    // signed long l;
    // signed long long ll;

    // unsigned char c;
    // unsigned short s;
    // unsigned int i;
    // unsigned long l;
    // unsigned long long ll;

    //example of integer overflow
    unsigned short x = 65535; // largest 16-bit unsigned value possible
    std::cout << "x was: " << x << std::endl;
    x = x + 1; // 65536 is out of our range -- we get overflow because x can't hold 17 bits
    std::cout << "x = x + 1\nx is now: " << x << std::endl;
    x = x - 1;
    std::cout << "x = x - 1\nx is now: " << x << std::endl;
    return 0;
}