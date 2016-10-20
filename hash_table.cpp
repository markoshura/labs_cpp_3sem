#include <cstdlib>
#include <iostream>
#include <cmath>

#include "doubleList.h"

const int N_MAX = 10000;

using namespace std;

int myHash(int x){
    return (int)hash<int>()(x) % N_MAX; //Берётся хэш от x, явно приводится к int
}

struct hashTable{
    List *values = new List[N_MAX];
};

void add( hashTable *table, int x)
{
    List *current = &(table->values[myHash(x)]);
    add(current, x);
}

int find(hashTable *table, int check_x){

    List *current = &(table->values[myHash(check_x)]);
    find(current, check_x);
}

void pop(hashTable *table, int pop_x){

    List * current = &(table->values[myHash(pop_x)]);
    int index = find(current, pop_x);
    pop(current, index);
}

int main(void){

    hashTable *table = new hashTable;
    for (int i = 0; i < 20; i++) {
        int x = rand() / 1000000;
        add(table, x);
    }
    cout << find(table, 1804) << endl;
    add(table, 2);
    cout << find(table, 2) << endl;
    pop(table, 2);
    cout << find(table, 2) << endl;
    return 0;
}
