#include<iostream>
using namespace std;

class Student{
    const int rollNum;
    public:
    Student(int r):rollNum(r){}
    void displayRollNum(){
        cout<<"Student details"<<endl;
        cout<<"Roll Number: "<<rollNum<<endl;
    }
};

int main(){
    int roll;
    cout<<"enter student roll no: ";
    cin>>roll;
    Student sara(roll);
    sara.displayRollNum();
    return 0;
}