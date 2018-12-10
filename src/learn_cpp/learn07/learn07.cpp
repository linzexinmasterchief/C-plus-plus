#include<iostream>
//examples of different kind of macros

//define a macro MAX if it is not defined
#ifndef MAX
//a function is defined inside the macro
#define MAX
//define max function template
int max(int x, int y);
//end the macro define
#endif

/*
 * one word contains 2 bytes,
 * AND 255 (0000,0000,1111,1111) to get the higher/right_hand_side byte
 * move all bits 8 digits to the left to get the lower byte
*/
#define WORD_LOW(xxx) ((char)(xxx) & 255)
#define WORD_HIGH(xxx) ((char)(xxx) >> 8)

using namespace std;
int main(){
    #warning "Henry is a study god"
    char in_word = 'a';
    
    #ifdef WORD_LOW
        //the #include macro could be written anywhere, although it will be much harder to read
        #include<stdio.h>
        printf("The lower byte is: %c \n", WORD_LOW(in_word));
    #endif

    int a = 2;
    int b = 3;

    #ifdef MAX
        cout << "Function max exist, the max amoung " << a << " and " << b << " is " << max(a, b) << endl;
    #endif

    #ifndef MAX
        //output a compiling error message if max template does not exist
        #error "Function max does not exist."
    #endif

    return 0;
}

int max(int x, int y){
    //return x if x > y, else return y
    return (x > y) ? x : y;
}