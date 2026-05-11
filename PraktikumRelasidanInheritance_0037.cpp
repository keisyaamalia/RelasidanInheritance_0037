#include <iostream>
#include <vector>
#include <string>
using namespace std;

class User {
public:
    static int globalId;
    int id;
    string nama;
    string email;
    
    static int generateId() {
        return ++globalId;
    }
    
    User(string n, string e) : nama(n), email(e), id(generateId()) {}
};

int User::globalId = 0;