#include<iostream>

using namespace std;

int main(){
    // for loop
    // i=0, i++ => i=i+1
    cout << "for loop:" << endl;
    for (int i = 0; i <= 5; i++) {
        cout << "Hello World" << endl;
    }

    cout << "-----------------------" << endl;

    // while loop
    cout << "while loop:" << endl;
    int i = 0;
    int j = 1;
    while (i <= 5 && j <= 3) {
        cout << "Hello World" << endl;
        i ++;
        j ++;
    }

    cout << "-----------------------" << endl;

    // if statement
    // if..else if...else
    int x = 0;
    int y = 1;
    if (x > 0 && y > 0) {
        cout << "larger than 0" << endl;
    } else if (x < 0 || y < 0) {
        cout << "not larger than 0" << endl;
    } else {
        cout << "other" << endl;
    }

    int a = 0;
    while (a < 10) {
        int b = 0;
        while (b < 20) {
            if (a >= b) {
                cout << a << " x " << b << " = " << a * b << " | ";
            }
            b ++;
        }
        cout << "" << endl;
        a ++;
    }
    
    return 0;
}