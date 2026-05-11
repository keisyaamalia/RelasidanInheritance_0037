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

class Member : public User {
public:
    bool status;
    
    Member(string n, string e, bool s = true) : User(n, e), status(s) {}
    
    void showProfile() {
        cout << "\n=== PROFILE MEMBER ===" << endl;
        cout << "ID: " << id << ", Nama: " << nama 
             << ", Email: " << email 
             << ", Status: " << (status ? "AKTIF" : "NON-AKTIF") << endl;
    }
};