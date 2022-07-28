#include <iostream>
#include <sqlite3.h>
#include <cstring>
#include <fstream>
#include <termios.h>
#include <stdio.h>
#include "misc.hpp"

#define menu "0.-Exit\n"               \
             "1.-New pass\n"           \
             "2.-Read pass\n"          \
             "3.-Re-New pass\n"        \
             "===========\n"           \
             "4.-Delete pass\n"        \
             "5.-Change pass\n"        \
             "6.-Change unique name\n" \
             "===========\n"           \
             "7.-Change email\n"       \
             "8.-Change account\n"     \
             "9.-Change page\n"        \
             "-> "


using namespace std;
  


int check_password(string password)
{
    if (password == "")
    {
        return 1;
    }
    /*
    read the password file
    */
    string password_readed = read_file("password.txt");
    
    if (password_readed == "")
    {
        return 1;
    }

    /*
     * Check if the password is valid
     */

    if (password_readed != hash_str(password))
    {
        return 1;
    }

    return 0;
}

bool get_password()
{

    char pass[128];
    string password;

    for (int i = 0; i < 3; i++)
    {
        cout << "password: ";
        cin.getline(pass, 128, '\n');
        password = pass;
        if (check_password(password) == 0)
        {
            return true;
        }
        cout << "Password is incorrect" << endl;
    }
    return false;
}

int main(int argc, char const *argv[])
{   
    if(!get_password()) return 0;

    sqlite3 *db;
    const char *filename = "passwords.db";
    
    if (sqlite3_open(filename, &db) != SQLITE_OK)
    {
        return handleError(db);
    }
    char opc;
    string password = "",uname = "",page = "",email = "",acount = "";
    while(opc != '0'){
        
        cout<<menu;
        cin>>opc;
        system(CLEAR_COMMAND);
        cout<<menu<<opc<<endl;
        switch (opc) {
        {
        case '0':{
            system(CLEAR_COMMAND);
            break;
        }
        case '1':{


        }

        default:{
            cout<<"unknown command \""<<opc<<"\""<<endl;
            break;
        }
        }
    }
    }
    

    return 0;
}
//compile with g++ main.cpp -lsqlite3 -lcurl -o crow