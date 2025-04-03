#include<iostream>
#include<string>
#define courseCount 5
using namespace std;

class Person{
    protected:
    string name, address, phoneNo, email;
    int id;
    public:
    Person(int i, string n, string a, string p, string e){
        name=n;
        id=i;
        email=e;
        phoneNo=p;
        address=a;
    }
    virtual void displayInfo(){
        cout<<"---------Personal Details-----------"<<endl;
        cout<<"Name: "<<name<<endl;
        cout<<"ID: "<<id<<endl;
        cout<<"Address: "<<address<<endl;
        cout<<"Phone Number: "<<phoneNo<<endl;
        cout<<"Email: "<<email<<endl;
    }
    void updateInfo(){
        int i;
        string n, add, e, phone;
        cout<<"enter updated details:"<<endl;
        cout<<"name: ";
        getline(cin,n);
        name=n;
        cout<<"ID: ";
        cin>>i;
        id=i;
        cin.ignore();
        cout<<"address: ";
        getline(cin,add);
        address=add;
        cout<<"phone number: ";
        getline(cin,phone);
        phoneNo=phone;
        cout<<"email: ";
        getline(cin,e);
        email=e;
        cout<<endl;
    }
};

class Student : public Person{
    string coursesEnrolled[courseCount];
    double GPA;
    string enrollmentYear;
    public:
    Student(int i, string n, string a, string p, string e, string course[], double gpa, string year) : Person(i,n,a,p,e){
        for (int i=0; i<courseCount; i++){
            coursesEnrolled[i]=course[i];
        }
        GPA=gpa;
        enrollmentYear=year;
    }
    void displayInfo()override{
        cout<<"---------Personal Details-----------"<<endl;
        cout<<"Name: "<<name<<endl;
        cout<<"ID: "<<id<<endl;
        cout<<"Address: "<<address<<endl;
        cout<<"Phone Number: "<<phoneNo<<endl;
        cout<<"Email: "<<email<<endl;
        cout<<"Courses enrolled in: "<<endl;
        for (int i=0; i<3; i++){
            cout<<"course "<<i+1<<": "<<coursesEnrolled[i]<<endl;
        }
        cout<<"GPA: "<<GPA<<endl;
        cout<<"Enrollment Year: "<<enrollmentYear<<endl;
    }
    string getName(){return name;}
    int getID(){return id;}
};

class Professor : public Person{
    string department;
    string coursesTaught[3];
    double salary;
    public:
    Professor(int i, string n, string a, string p, string e, string dept, string course[], double sal) : Person(i,n,a,p,e){
        department=dept;
        for (int i=0; i<3;i++){
            coursesTaught[i]=course[i];
        }
        salary=sal;
    }
    void displayInfo()override{
        cout<<"---------Professor Details-----------"<<endl;
        cout<<"Name: "<<name<<endl;
        cout<<"ID: "<<id<<endl;
        cout<<"Address: "<<address<<endl;
        cout<<"Phone Number: "<<phoneNo<<endl;
        cout<<"Email: "<<email<<endl;
        cout<<"Department: "<<department<<endl;
        cout<<"Courses taught: "<<endl;
        for (int i=0; i<3; i++){
            cout<<"course "<<i+1<<": "<<coursesTaught[i]<<endl;
        }
        cout<<"Salary: "<<salary<<endl;
    }
};

class Staff : public Person{
    string department;
    string position;
    double salary;
    public:
    Staff(int i, string n, string a, string p, string e, string dept, string pos, double sal) : Person(i,n,a,p,e){
        department=dept;
        position=pos;
        salary=sal;
    }
    void displayInfo()override{
        cout<<"---------Staff Details-----------"<<endl;
        cout<<"Name: "<<name<<endl;
        cout<<"ID: "<<id<<endl;
        cout<<"Address: "<<address<<endl;
        cout<<"Phone Number: "<<phoneNo<<endl;
        cout<<"Email: "<<email<<endl;
        cout<<"Department: "<<department<<endl;
        cout<<"Position: "<<position<<endl;
        cout<<"Salary: "<<salary<<endl;
    }
};

class Course{
    int courseID;
    string courseName;
    int credits;
    string instructor;
    string schedule;
    public:
    Course(int id, string n, int cr, string in, string sc){
        courseID=id;
        credits=cr;
        instructor=in;
        schedule=sc;
        courseName=n;
    }
    void registerStudent(Student &s){
        cout<<"Student "<<s.getName()<<", ID: "<<s.getID()<<" registered for "<<courseName<<endl;
    }
    void calculateGrades(){
        cout<<"Grade calculation in process...."<<endl;
    }
};

int main() {
    string studentCourses[] = {"Math", "Physics", "CS", "English", "History"};
    string professorCourses[] = {"CS101", "AI", "Data Structures"};

    Student s1(101, "Alice", "123 Street", "123456789", "alice@email.com", studentCourses, 3.8, "2023");
    Professor p1(202, "Dr. Bob", "456 Avenue", "987654321", "bob@university.com", "Computer Science", professorCourses, 75000);
    Staff st1(303, "Charlie", "789 Boulevard", "5647382910", "charlie@university.com", "Admin", "Manager", 50000);
    Course c1(111, "Data Structures", 3, "Dr. Bob", "MWF 10-11 AM");

    s1.displayInfo();
    p1.displayInfo();
    st1.displayInfo();

    c1.registerStudent(s1);
    c1.calculateGrades();
    
    cout<<endl;
    s1.updateInfo();
    s1.displayInfo();
    return 0;
}


