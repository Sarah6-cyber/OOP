#include<iostream>
#include<string>
using namespace std;

struct Employee
{
    int employee_id;
    string name;
    float salary;
};
struct Organization
{
    string organisation_name;
    string organisation_number;
    struct Employee emp;
};

int main(){
    struct Organization org;
    org.organisation_name="NU-Fast";
    org.organisation_number="NUFAST123ABC";
    org.emp.employee_id=127;
    org.emp.name="Linus Sebastian";
    org.emp.salary=400000;
    cout<<"the size of structure organization: "<<sizeof(org)<<endl;
    cout<<"Organization name: "<<org.organisation_name<<endl;
    cout<<"Organization number: "<<org.organisation_number<<endl;
    cout<<"Employee ID: "<<org.emp.employee_id<<endl;
    cout<<"Employee name: "<<org.emp.name<<endl;
    cout<<"Employee salary: "<<org.emp.salary<<endl;
    return 0;
}