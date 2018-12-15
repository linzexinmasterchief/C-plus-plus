#include <iostream>

//example of infinity and invalid
int main()
{
    double zero = 0.0;
    double posinf = 5.0 / zero; // positive infinity
    std::cout << posinf << std::endl;
 
    double neginf = -5.0 / zero; // negative infinity
    std::cout << neginf << std::endl;
 
    double nan = zero / zero; // not a number (mathematically invalid)
    std::cout << nan << std::endl;
 
    return 0;
}