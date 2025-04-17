#include<iostream>
using namespace std;

class Wallet{
    double balance;
    double withdrawLimit=5000;
    double depositLimit=10000;
    double totalWithdrawal;
    double totalDeposited;
    public:
    Wallet(double bal) : balance(bal), totalDeposited(0), totalWithdrawal(0){}
    void deposit(double amt){
        if (amt<0){
            cout<<"incorrect amount entered"<<endl;
            return;
        }
        if (totalDeposited+amt>depositLimit){
            cout<<"transaction limit exceeded. cannot deposit"<<endl;
            return;
        }
        else {
            balance+=amt;
            totalDeposited+=amt;
            cout<<amt<<" deposited"<<endl;
        }
    }
    void withdraw(double amt){
        if (amt<0){
            cout<<"incorrect amount entered"<<endl;
            return;
        }
        if (amt>balance){
            cout<<"insufficient balance. cannot withdraw"<<endl;
            return;
        }
        if (totalWithdrawal+amt>withdrawLimit){
            cout<<"transaction limit exceeded. cannot withdraw"<<endl;
            return;
        }
        else {
            balance-=amt;
            totalWithdrawal+=amt;
            cout<<amt<<" withdrawn"<<endl;
        }
    }
    double getBalance(){return balance;}
};

class User{
    string name;
    int userID;
    Wallet wallet;
    public:
    User(string n, int id, double bal) : name(n), userID(id), wallet(bal){}
    void withdraw(double amt){
        wallet.withdraw(amt);
    }
    void deposit(double amt){
        wallet.deposit(amt);
    }
    void display(){
        cout<<"----User Details-------"<<endl;
        cout<<"Name: "<<name<<endl;
        cout<<"ID: "<<userID<<endl;
        cout<<"Balance: "<<wallet.getBalance()<<endl;
        cout<<"------------------------"<<endl;
    }
};

int main(){
    User u1("sara",101,3400);
    u1.deposit(10000);
    u1.withdraw(2000);
    u1.withdraw(4000);
    u1.display();

    User u2("zaviyar",102,6000);
    u2.deposit(5000);
    u2.withdraw(4000);
    u2.deposit(10000);
    u2.display();
    return 0;
}