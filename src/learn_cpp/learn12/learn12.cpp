#include <iostream>
 
using namespace std;
//c++ scientific demonstration of double and float
int main()
{
    int x(5); // 5 means integer
    double y(5.0); // 5.0 is a floating point literal (no suffix means double type by default)
    float z(5.0f); // 5.0 is a floating point literal, f suffix means float type

	cout << 5.0 << endl;
	cout << 6.7f << endl;
	cout << 9876543.21 << endl;
        
    double d1(5000.0);
    double d2(5e3); // another way to assign 5000
    
    double d3(0.00000005);
    double d4(5e-7); // another way to assign 0.05
    
    cout << "statment d1 = d2 is " << (d1 == d2) << endl;
    cout << "statment d3 = d4 is " << (d3 == d4) << endl;

    cout << "d4 was " << d4 << endl;
    d4 = d4 * 10000000; //1e7
    cout << "d4 is now " << d4 << endl;

    return 0;
}