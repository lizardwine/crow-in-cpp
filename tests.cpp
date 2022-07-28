#include<iostream>
#include "misc.hpp"

using namespace std;

int main(int argc, char const *argv[])
{
    cout<<hash_str("1234");
    return 0;
}
//compile with g++ tests.cpp -lsqlite3 -lcurl -o test