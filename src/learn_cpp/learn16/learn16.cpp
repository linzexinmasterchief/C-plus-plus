#include<iostream>
#include<iomanip>

//fixed length output

using namespace std;
int main(){
    char* s;

    // s = "helloworld";
    cout << "[" << setw(20) << setfill(' ') << s << "]" << endl;
    s = "hello";
    cout << "[" << setw(20) << setfill(' ') << s << "]" << endl;

    //align to left
    s = "hellohello";
    cout << "[" << setw(20) << left << setfill(' ') << s << "]" << endl;
    return 0;
}