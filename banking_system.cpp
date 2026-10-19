#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Account {
public:
    string name; int accNo; double balance;
    Account(string n, int no, double b){ name=n; accNo=no; balance=b; }
    void deposit(double amt){ balance+=amt; cout << "Deposited: " << amt << endl; }
    void withdraw(double amt){ if(amt<=balance){ balance-=amt; cout << "Withdrawn: " << amt << endl; } else cout << "Insufficient Balance!\n"; }
    void display(){ cout << "\nAccount: " << accNo << " | Name: " << name << " | Balance: " << balance << endl; }
};

int main(){
    vector<Account> accounts;
    int choice;
    while(true){
        cout << "\n--- Banking System ---\n1. Create Account\n2. Deposit\n3. Withdraw\n4. Display All\n5. Exit\nChoice: "; cin >> choice;
        if(choice==1){ string n; int no; double b; cout<<"Name: "; cin>>n; cout<<"Acc No: "; cin>>no; cout<<"Initial Balance: "; cin>>b; accounts.push_back(Account(n,no,b)); }
        else if(choice==2){ int no; double amt; cout<<"Acc No: "; cin>>no; cout<<"Amount: "; cin>>amt; for(auto &a: accounts) if(a.accNo==no) a.deposit(amt); }
        else if(choice==3){ int no; double amt; cout<<"Acc No: "; cin>>no; cout<<"Amount: "; cin>>amt; for(auto &a: accounts) if(a.accNo==no) a.withdraw(amt); }
        else if(choice==4){ for(auto &a: accounts) a.display(); }
        else if(choice==5) break;
    }
    return 0;
}