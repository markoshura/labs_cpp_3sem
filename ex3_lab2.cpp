#include <iostream>
using namespace std;
void good_incrementor(int &x)
{
    x++;
    std::cout << "x changed: " << x << std::endl;
}


int main()
{
    int c = 1;
    std::cout << "c initial: " << c << std::endl;
    good_incrementor(c);
    std::cout << "c changed: " << c << std::endl;

    return 0;
}
