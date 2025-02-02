#include<iostream>
#include<string>
using namespace std;

struct Courses
{
    string subject;
};
struct Student
{
    int ID;
    Courses Subjects[5];
};

int main(){
    int count;
    cout<<"enter number of students: ";
    cin>>count;
    Student *student=new Student[count];
    cout<<"enter info"<<endl;
    for (int i=0; i<count; i++){
        cout<<"for student "<<i+1<<endl;
        cout<<"enter id: ";
        cin>>student[i].ID;
        cin.ignore();
        cout<<"enter subjects: "<<endl;
        for (int j=0; j<5; j++){
            cout<<"subject "<<j+1<<": ";
            getline(cin, student[i].Subjects[j].subject);
        }
    }
    for (int i=0; i<count; i++){
        cout<<"student "<<i+1<<endl;
        cout<<"id: "<<student[i].ID<<endl;
        for (int j=0; j<5; j++){
            cout<<"subject "<<j+1<<": "<<student[i].Subjects[j].subject<<endl;
        }
    }
    delete[] student;
    return 0;
}