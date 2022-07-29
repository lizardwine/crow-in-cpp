#include<iostream>
#include "misc.hpp"

using namespace std;

int main(int argc, char const *argv[])
{
    cout << "\033[1;31mbold red text\033[0m\n";
    return 0;
}
//compile with g++ tests.cpp -lsqlite3 -lcurl -o test