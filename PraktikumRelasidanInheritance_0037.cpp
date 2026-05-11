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

class Admin : public User {
public:
    vector<User*> members;
    
    Admin(string n, string e) : User(n, e) {}
    
    void addMember(User* m) { members.push_back(m); }
    
    void showAllMember() {
        cout << "\n=== DAFTAR MEMBER ===" << endl;
        for (auto m : members) {
            cout << "ID: " << m->id << ", " << m->nama << " (" << m->email << ")" << endl;
        }
    }
    
    void toggleActivationMember(int targetId) {
        for (auto m : members) {
            if (m->id == targetId) {
                Member* mem = static_cast<Member*>(m);
                mem->status = !mem->status;
                cout << "✓ Status " << mem->nama << " → " 
                     << (mem->status ? "AKTIF" : "NON-AKTIF") << endl;
                return;
            }
        }
        cout << "✗ ID " << targetId << " tidak ditemukan!" << endl;
    }
};

int main() {
    Admin admin("Admin", "admin@co.com");
    Member m1("Budi", "budi@co.com");
    Member m2("Siti", "siti@co.com", false);
    
    admin.addMember(&m1);
    admin.addMember(&m2);
    
    admin.showAllMember();
    admin.toggleActivationMember(1);
    admin.toggleActivationMember(2);
    
    m1.showProfile();
    m2.showProfile();
    
    return 0;
}