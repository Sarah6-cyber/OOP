#include<iostream>
using namespace std;

class Person{
    protected:
    string name;
    double bonus, salary;
    public:
    Person(string n, double sal){
        name=n;
        salary=sal;
    }
    string getData(){return name;}
    virtual void displayData(){
        cout<<"Name: "<<name<<endl;
        cout<<"Salary: "<<salary<<endl;
    }
    virtual double Bonus()=0;
};

class Admin : virtual public Person{
    public:
    Admin(string n, double sal) : Person(n,sal){}
    double Bonus()override{
        return salary*0.05;
    }
    void displayData()override{
        cout<<"----Admin-----"<<endl;
        cout<<"Name: "<<name<<endl;
        cout<<"Salary: "<<salary<<endl;
        cout<<"Bonus: "<<Bonus()<<endl;
    }
};

class Account : virtual public Person{
    public:
    Account(string n, double sal) : Person(n,sal){}
    double Bonus()override{
        return salary*0.02;
    }
    void displayData()override{
        cout<<"---Account------"<<endl;
        cout<<"Name: "<<name<<endl;
        cout<<"Salary: "<<salary<<endl;
        cout<<"Bonus: "<<Bonus()<<endl;
    }
};

class Master : public Admin ,public Account{
    public:
    Master(string n, double sal) : Admin(n,sal), Account(n,sal), Person(n,sal){}
    double Bonus()override{
        return salary*0.09;
    }
    void displayData()override{
        cout<<"----Master------"<<endl;
        cout<<"Name: "<<name<<endl;
        cout<<"Salary: "<<salary<<endl;
        cout<<"Bonus: "<<Bonus()<<endl;
    }
};

int main(){
    Person *p;
    Admin ad("sara",25000);
    Account acc("aurora",23000);
    Master ma("meryem",30000);
    
    p=&ad;
    p->displayData();

    p=&acc;
    p->displayData();

    p=&ma;
    p->displayData();

    return 0;
}