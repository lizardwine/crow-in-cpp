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
    cout<<"\033[1;32mCreating database.\033[0m"<<endl;
    sqlite3 *db;
    sqlite3_open(filename, &db);
    if (sqlite3_exec(db, CREATE_TABLE_PASSWORDS, nullptr, nullptr, nullptr) != SQLITE_OK)
    {
        handleError(db);
    }
    else{
        cout<<"\033[1;34mdone.\033[0m"<<endl;
    }
    sqlite3_close(db);
}

int main(int argc, char const *argv[])
{   
    const string crow_directory = OS_DIRECTORY + getUserName() + "/crow";
    const string passwords_directory = crow_directory + "/passwords.db";
    const string mkdir_command = "mkdir " + crow_directory;
    const string url = "https://github.com/lizardwine/crow-in-cpp/raw/main/crow";
    const string crow_exe_directory = crow_directory + "/crow" + FILE_TYPE;
    //create crow directory
    if(!exists_path(crow_directory.c_str())){
        cout<<"\033[1;32mCreating directory...\033[0m"<<endl;
        system(mkdir_command.c_str());
        cout<<"\033[1;34mdone.\033[0m"<<endl;
    }
    if(!exists_path(passwords_directory.c_str())){
        create_database(passwords_directory.c_str());
    }
    download(url,crow_exe_directory);
    cout<<endl;
    return 0;
}
//compile with g++ installer.cpp -lsqlite3 -lcurl -o installer