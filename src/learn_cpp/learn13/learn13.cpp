#include<iostream>
#include <iomanip> // for std::setprecision()

//example of float precision and range

int main(){
    float f;
    f = 9.87654321f; // f suffix means this number should be treated as a float
    std::cout << f << std::endl;
    f = 987.654321f;
    std::cout << f << std::endl;
    f = 987654.321f;
    std::cout << f << std::endl;
    f = 9876543.21f;
    std::cout << f << std::endl;
    f = 0.0000987654321f;
    std::cout << f << std::endl;

    std::cout << std::setprecision(16); // show 16 digits
    float f_precise = 3.33333333333333333333333333333333333333f;
    std::cout << f_precise << std::endl;
    double d_precise = 3.3333333333333333333333333333333333333;
    std::cout << d_precise << std::endl;

    //lose precision
    f = 123456789.0f; // f has 10 significant digits
    std::cout << std::setprecision(9); // to show 9 digits in f
    std::cout << f << std::endl; //output 123456792 > 123456789.0

    //Rule: Favor double over float unless space is at a premium,
    //as the lack of precision in a float will often lead to inaccuracies.



    //Rounding errors
    double d(0.1);
    std::cout << d << std::endl; // use default cout precision of 6
    std::cout << std::setprecision(17);
    std::cout << d << std::endl;

    
    std::cout << std::setprecision(17);

    double d1(1.0);
    std::cout << d1 << std::endl; //output 1
	
    double d2(0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1); // should equal 1.0
    std::cout << d2 << std::endl; //output 0.99999999999999989

    return 0;
}