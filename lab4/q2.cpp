#include<iostream>
using namespace std;

class Account{
    double balance;
    public:
    Account(double b){
        if(b<0){
            balance=0.0;
        }
        else {
            balance=b;
        }
    }
    double getBalance(){
        return balance;
    }
    double Credit(double amt){
        balance+=amt;
        return balance;
    }
    double Debit(double amt){
        balance-=amt;
        return balance;
    }
};

int main(){
    double bal;
    cout<<"enter account balance: "<<endl;
    cin>>bal;
    Account a(bal);
    double amount;
    double withdraw;
    int choice;
    while (true)
    {
        cout<<"1.check balance"<<endl;
        cout<<"2.add amount"<<endl;
        cout<<"3.withdraw amount"<<endl;
        cout<<"4.exit program"<<endl;
        cout<<"enter choice: "<<endl;
        cin>>choice;
       switch (choice)
       {
       case 1:
        cout<<"current balance: "<<a.getBalance()<<endl;
        break;
       case 2:
        cout<<"enter amount: "<<endl;
        cin>>amount;
        cout<<"updated balance: "<<a.Credit(amount)<<endl;
        break;
       case 3:
        cout<<"enter amount you want to withdraw: "<<endl;
        cin>>withdraw;
        cout<<"updated balance after withdrawal: "<<a.Debit(withdraw)<<endl;
        break;
       case 4:
        return 0;
       default:
        cout<<"incorrect choice!"<<endl;
        break;
       }
    }
    return 0;
}