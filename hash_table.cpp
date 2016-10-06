#include <iostream>
#include <cstring>
using namespace std;
struct Node
{
    Node *next, *prev;
    string *key;
    string *value;
};

Node *hashTable[32];

int my_hash(string &str)
{
    int hash_value = 0;
    const char *p = str.c_str();
    while(*p) {
        hash_value = 31 * hash_value + *p;
        ++p;
    }
    return abs(hash_value) % 32;
}

Node *insert_node(string *key, string *value)
{
    int hash_value = 0;
    Node *new_node;


}
