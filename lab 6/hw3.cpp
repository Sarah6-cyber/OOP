#include<iostream>
using namespace std;

class Student{
    protected:
    int studentID;
    string name;
    string department;
    public:
    Student(int id, string n, string d) : studentID(id), name(n), department(d){}
    void displayInfo(){
        cout<<"----STUDENT INFO-----"<<endl;
        cout<<"Student ID: "<<studentID<<endl;
        cout<<"Student Name: "<<name<<endl;
        cout<<"Department enrolled: "<<department<<endl;
    }
};

class Marks : public Student{
    protected:
    float *marks;
    int courseCount;
    public:
    Marks(int id, string n, string dept,int count, float *m) : Student(id,n,dept){
        courseCount=count;
        marks=new float[courseCount];
        for (int i=0; i<courseCount; i++){
            marks[i]=m[i];
        }
    }
    void displayMarks(){
        cout<<"------Student Marks------"<<endl;
        for (int i=0; i<courseCount; i++){
            cout<<"Course "<<i+1<<": "<<marks[i]<<endl;
        }
    }
    ~Marks(){
        delete [] marks;
    }
};

class result : public Marks{
    float avg;
    float total;
    public:
    result(int id, string n, string d, int c, float *m) : Marks(id,n,d,c,m){
        avg=0;
        total=0;
    }
    void displayCalculation(){
        for (int i=0; i<courseCount; i++){
            total+=marks[i];
        }
        avg=total/courseCount;
        cout<<"Total Marks in "<<courseCount<<" courses: "<<total<<endl;
        cout<<"Average Marks: "<<avg<<endl;
    }
};

int main(){
    float mark[]={99,98,78,67,91,93};
    int count_of_course=6;
    result r(101,"sara","CS",count_of_course,mark);
    r.displayInfo();
    r.displayMarks();
    r.displayCalculation();
    return 0;
}