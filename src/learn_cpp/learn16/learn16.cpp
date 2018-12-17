#include<iostream>
#include<iomanip>

//fixed leangth output

using namespace std;
int main(){
    char* s;

    s = "helloworld";
    cout << "[ First string  " << setw(20) << setfill(' ') << s << " ]" << endl;
    s = "hello";
    cout << "[ Second string " << setw(20) << setfill(' ') << s << " ]" << endl;

    //exceeds width 20 range
    s = "hellohellohellohellohello";
    cout << "[ Third string " << setw(20) << setfill(' ') << s << " ]" << endl;
    return 0;
}