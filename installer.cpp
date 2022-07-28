#include <iostream>
#include "misc.hpp"
#include <sqlite3.h>
#define CREATE_TABLE_PASSWORDS "CREATE TABLE \"passwords\" (" \
                               "\"id\"    INTEGER UNIQUE,"    \
                               "\"password\"  TEXT,"          \
                               "\"account\"   TEXT,"          \
                               "\"page\"  TEXT,"              \
                               "\"email\" TEXT,"              \
                               "\"uname\" TEXT UNIQUE,"       \
                               "PRIMARY KEY(\"id\" AUTOINCREMENT));"

using namespace std;

void create_database(const char *filename)
{
    cout << "Creating database..." << endl;
    sqlite3 *db;
    sqlite3_open(filename, &db);
    if (sqlite3_exec(db, CREATE_TABLE_PASSWORDS, nullptr, nullptr, nullptr) != SQLITE_OK)
    {
        handleError(db);
    }
    else{
        cout << "done." << endl;
    }
    sqlite3_close(db);
}

int main(int argc, char const *argv[])
{   
    string crow_directory = OS_DIRECTORY + getUserName() + "/crow";
    string passwords_directory = crow_directory + "/passwords.db";
    string mkdir_command = "mkdir " + crow_directory;
    string url = "https://raw.githubusercontent.com/p-ranav/indicators/v2.2/single_include/indicators/indicators.hpp";
    string crow_exe_directory = crow_directory + "/crow" + FILE_TYPE;
    //create crow directory
    if(!exists_path(crow_directory.c_str())){
        cout<<"Createing directory..."<<endl;
        system(mkdir_command.c_str());
        cout<<"done."<<endl;
    }
    create_database(passwords_directory.c_str());
    


    return 0;
}
//compile with g++ installer.cpp -lsqlite3 -lcurl -o installer