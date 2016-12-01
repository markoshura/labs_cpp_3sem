#include <iostream>
#include <thread>
#include <mutex>
using namespace std;
int x; mutex m;

void threadFunction1()
{
    for( int i = 0; i < 1000003; ++i ) {
        m.lock();
        x++;
        m.unlock();
    }
}

void threadFunction2()
{
    for( int i = 0; i < 1000000; ++i ) {
        m.lock();
        if ( (x%2) == 0 ) {

            std::cout << "x = " << x << std::endl;

        }
        m.unlock();
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
