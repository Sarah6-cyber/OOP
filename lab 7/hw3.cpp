#include<iostream>
using namespace std;

class Person{
    protected:
    int id;
    public:
    Person(int i) : id(i){}
    int getData(){return id;}
    virtual void displayData(){
        cout<<"Employee ID: "<<id<<endl;
    }
};

class Admin : public Person{
    string name;
    float income;
    public:
    Admin(int id, string n, float inc) : Person(id){
        name=n;
        income=inc;
    }
    float Bonus(){
        float b;
        b=income*0.05*12; 
        return b;
    }
    void displayData(){
        Person::displayData();
        cout<<"Employee Name: "<<name<<endl;
        cout<<"Monthly income: "<<income<<endl;
        cout<<"Annual bonus: "<<Bonus()<<endl;
    }
};

class Accounts : public Person{
    string name;
    float income;
    public:
    Accounts(int id, string n, float inc) : Person(id){
        name=n;
        income=inc;
    }
    float Bonus(){
        float b;
        b=income*12*0.05;
        return b; 
    }
    void displayData(){
        Person::displayData();
        cout<<"Employee Name: "<<name<<endl;
        cout<<"Monthly income: "<<income<<endl;
        cout<<"Annual Bonus: "<<Bonus()<<endl;
    }
};

int main(){
    Admin a(101,"Faris",3400.05);
    Accounts acc(1001,"Hashim",3200.25);
    a.displayData();
    acc.displayData();
    return 0;
}

