#include<iostream>
#include<string>
#include<cstdlib>
using namespace std;

class Employee{
    string firstName;
    string lastName;
    double salary;
    public:
    string get_firstName(){
        return firstName;
    }
    string get_lastName(){
        return lastName;
    }
    double get_salary(){
        return salary;
    }
    void set_firstName(string f){
        firstName=f;
    }
    void set_lastName(string l){
        lastName=l;
    }
    void set_salary(double s){
        salary=s;
        if (salary<0.0){
            salary=0.0;
        }
    }
    void updateSalary(){
        double amt=(10.0/100.0)*salary;
        salary+=amt;
    }
    void EmployeeTest(){
        cout<<"Name of Employee: "<<firstName<<" "<<lastName<<endl;
        cout<<"salary before raise: "<<salary<<endl;
        updateSalary();
        cout<<"salary after raise: "<<salary<<endl;
    }
};

int main(int argc, char *argv[]){
    if (argc!=7){
        cout<<"enter details for two employees only with format: first name , last name , salary"<<endl;
        return 1;
    }
    Employee e1, e2;
    e1.set_firstName(argv[1]);
    e1.set_lastName(argv[2]);
    e1.set_salary(atof(argv[3]));
    e2.set_firstName(argv[4]);
    e2.set_lastName(argv[5]);
    e2.set_salary(atof(argv[6]));
    e1.EmployeeTest();
    e2.EmployeeTest();
    return 0;
}