#include <iostream>
#include <thread>
#include <mutex>
using namespace std;
int x; mutex m;

void threadFunction1()
{
    for( int i = 0; i < 1000003; ++i ) {

        x++;

    }
}

void threadFunction2()
{
    for( int i = 0; i < 1000000; ++i ) {
        int y = x;

        if ( (y%2) == 0 ) {

            std::cout << "x = " << y << std::endl;

        }

    }

}

int main()
{
    std::thread t1(threadFunction1);
    std::thread t2(threadFunction2);
    t1.join();
    t2.join();
    return 0;
}
