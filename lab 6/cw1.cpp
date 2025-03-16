#include<iostream>
using namespace std;

class BankAccount{
    protected:
    string accNumber;
    double balance;
    public:
    BankAccount(double bal, string num){
        accNumber=num;
        balance=bal;
        cout<<"bank account created"<<endl;
    }
    void deposit(double amt){
        if (amt>0){
            balance+=amt;
            cout<<amt<<" deposited successfully"<<endl;
        }
        else {
            cout<<"incorrect amount entered"<<endl;
        }
    }
    void withdraw(double amt){
        if (amt<=balance){
            cout<<amt<<" withdrawn successfully"<<endl;
        }
        else {
            cout<<"withdrawal not successful due to insufficient balance"<<endl;
        }
    }
    void displayAccount(){
        cout<<"Account Number: "<<accNumber<<endl;
        cout<<"Current Balance: "<<balance<<endl;
    }
};

class SavingsAccount : public BankAccount{
    float interestRate;
    public:
    SavingsAccount(double bal, string num, float rate) : BankAccount(bal,num){}
    public:
    void applyInterest(){
        double interest;
        interest=balance*(interestRate/100);
        balance+=interest;
    }
};

class CheckingAccount : public BankAccount{
    double limit;
    public:
    CheckingAccount(double bal, string num, double limit) : BankAccount(bal,num){
        limit=this->limit;
    }
    void overDraft(double amt){
        if (balance-amt<-limit){
            cout<<"transaction denied as overdraft limit is exceeding"<<endl;
        }
        else {
            balance-+amt;
            cout<<amt<<" withdrawn"<<endl;
        }
    }
};

class BusinessAccount : public BankAccount{
    double taxRate;
    public:
    BusinessAccount(double bal, string num, double rate) : BankAccount(bal,num){
        taxRate=rate;
    }
    void corporateTax(double amt){
        double tax;
        tax=balance*(taxRate/100);
        balance+=(amt-tax);
        cout<<amt<<" deposited with tax: "<<tax<<endl;
    }
};

class Customer{
    int customerID;
    string name;
    BankAccount *acc;
    public:
    Customer(int id, string n, string accNum, double bal){
        customerID=id;
        name=n;
        acc=new BankAccount(bal,accNum);
    }
    void customerWithdraws(double amt){
        acc->withdraw(amt);
    }
    void customerDeposits(double amt){
        acc->deposit(amt);
    }
    void displayCustomerAcc(){
        cout<<"-------Customer Accounts-------"<<endl;
        acc->displayAccount();
    }
};

class Employee{
    protected:
    int employeeID;
    string name;
    public:
    Employee(int id, string n) : employeeID(id), name(n){}
    void display(){
        cout<<"-------Employee Info---------"<<endl;
        cout<<"ID: "<<employeeID<<endl;
        cout<<"Name: "<<name<<endl;
    }
};

class Teller : public Employee{
    public:
    Teller(int id, string n) : Employee(id,n){}
    void tellerWithdraws(BankAccount &acc, double amt){
        acc.withdraw(amt);
    }
    void tellerDeposits(BankAccount &acc, double amt){
        acc.deposit(amt);
    }
    void freezeAccount(){
        cout<<"account freezed by Teller...."<<endl;
    }
};

class Manager : public Employee{
    public:
    Manager(int id, string n) : Employee(id,n){}
    void overrideLimit(CheckingAccount &ch, double lim){
        cout<<"Manager overriding limit to "<<lim<<endl;
    }
    void adjustbalance(BankAccount &acc, double amt){
        cout<<"Balance adjusted to "<<amt<<endl;
    }
};

int main(){
    SavingsAccount S(5000, "SA123", 2.5);  
    CheckingAccount C(3000, "CH456", 4500); 
    BusinessAccount B(10000, "BS789", 2.0); 

    cout<<"------Initial Account Details------"<<endl;
    S.displayAccount();
    C.displayAccount();
    B.displayAccount();

    S.applyInterest();
    cout<<"After applying interest: "<<endl;
    S.displayAccount();

    cout<<"Checking Account Overdraft Test: "<<endl;
    C.overDraft(3500);  
    C.displayAccount();
    C.overDraft(7000);  

    cout<<"Business Account Deposit Test: "<<endl;
    B.corporateTax(5000); 
    B.displayAccount();

    Customer c1(101, "Sara", "SA123", 6000);
    cout<<endl<<"Customer Initial Details: "<<endl;
    c1.displayCustomerAcc();

    c1.customerDeposits(2500);
    c1.customerWithdraws(540);
    cout<<endl<<"Customer After Transactions: "<<endl;
    c1.displayCustomerAcc();

    Teller t(2345, "Anaya");
    cout <<endl<<"Teller Transactions: "<<endl;
    t.tellerDeposits(S, 2000);
    t.tellerWithdraws(C, 1000);
    t.freezeAccount();
    S.displayAccount();
    C.displayAccount();

    Manager m(1001, "Arham");
    cout<<endl<<"Manager's Call:"<<endl;
    m.overrideLimit(C, 2000);
    m.adjustbalance(S, 8000);

    return 0;
}