#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Account{
    protected:
    int accNumber;
    string accHolder;
    float balance;
    string accType;
    vector<string>transaction;
    public:
    Account(int num, string name, string type, float bal){
        accNumber=num;
        accHolder=name;
        accType=type;
        balance=bal;
    }
    void deposit(float amt){
        if (amt<=0){
            cout<<"amount invalid"<<endl;
        }
        else {
            balance+=amt;
            transaction.push_back("Deposited: $" + std::to_string(amt));
            cout<<"funds deposited"<<endl;
        }
    }
    virtual void withdraw(float amt){
        if (amt>balance){
            cout<<"insufficient balance in your account. amount withdrawal not successful"<<endl;
        }
        else {
            balance-=amt;
            transaction.push_back("Withdrew: $" + std::to_string(amt));
            cout<<"amount withdrawn"<<endl;
        }
    }
    virtual void printStatement(){
        if (transaction.empty()){
            cout<<"no transaction history"<<endl;
        }
        else {
            for (const std::string &transaction : transaction){
                cout<<transaction<<endl;
            }
        }
    }
    void getAccountInfo(){
        cout<<"Account Number: "<<accNumber<<endl;
        cout<<"Account Holder Name: "<<accHolder<<endl;
        cout<<"Account Type: "<<accType<<endl;
        cout<<"Balance: "<<balance<<endl;
    }
    virtual float calculateInterest(){
        return 0.0;
    }
};


class SavingsAccount : public Account{
    int int_rate;
    float min_balance;
    public:
    SavingsAccount(int i, int min, int num, string name, string type, float bal) : Account(num, name, type, bal){
        int_rate=i;
        min_balance=min;
    }
    void printStatement()override{
        Account::printStatement();
        cout<<"Interest rate: "<<int_rate<<endl;
        cout<<"Minimum balance: "<<min_balance<<endl;
    }
    float calculateInterest()override{
        return balance*(int_rate/100.0);
    }
};

class CheckingAccount : public Account{
    float overdraft;
    public:
    CheckingAccount(float o, int num, string name, string type, float bal) : Account(num, name, type, bal){
        overdraft=o;
    }
    void printStatement()override{
        Account::printStatement();
        cout<<"Overdraft limit: "<<overdraft<<endl;
    }
    void withdraw(float amt)override{
        if (amt>balance+overdraft){
            cout<<"overdraft limit exceeds. amount withdrawal not successful"<<endl;
        }
        else {
            balance-=amt;
            transaction.push_back("Withdrew: $" + std::to_string(amt));
            cout<<"amount withdrawn"<<endl;
        }
    }
};

class FixedDepositAccount : public Account{
    string maturityDate;
    int fixedInterest;
    public:
    FixedDepositAccount(string m, int f, int num, string name, string type, float bal) : Account(num, name, type, bal){
        maturityDate=m;
        fixedInterest=f;
    }
    void printStatement()override{
        Account::printStatement();
        cout<<"Maturity date: "<<maturityDate<<endl;
        cout<<"Fixed interest rate: "<<fixedInterest<<endl;
    }
    float calculateInterest()override{
        return balance*(fixedInterest/100);
    }
    void withdraw(float amt)override{
        cout<<"Withdrawals are not allowed before maturity date: "<<maturityDate<<endl;
    }
};

int main(){
    CheckingAccount ch(300.5,101,"Sara","Checking Account",35000);
    ch.deposit(2000);
    ch.withdraw(1250);
    ch.calculateInterest();
    ch.getAccountInfo();
    ch.printStatement();
    cout<<endl;

    SavingsAccount s(5,2000,102,"Zahra","Savings Account",10000);
    s.deposit(1000);
    s.withdraw(6500);
    s.calculateInterest();
    s.getAccountInfo();
    s.printStatement();
    cout<<endl;

    FixedDepositAccount f("02-05-25",3,103,"Rizwan","Fixed deposit Account",45000);
    f.deposit(500);
    f.withdraw(4500);
    f.calculateInterest();
    f.getAccountInfo();
    f.printStatement();
    cout<<endl;

    return 0;
}