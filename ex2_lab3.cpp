#include <iostream>
using namespace std;
void good_incrementor(int *x)
{
    (*x)++;
}


int main()
{
    int x = 1;
    std::cout << "x initial: " << x << std::endl;
    good_incrementor(&x);
    std::cout << "x changed: " << x << std::endl;

    return 0;
}
