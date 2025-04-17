#include<iostream>
using namespace std;

class Student{
    public:
    Student(){}
    virtual double getTuition(string status, int creditHours)=0;
};

class GraduateStudent : public Student{
    string topic;
    public:
    GraduateStudent() : topic(""){}
    void setTopic(string t){
        topic=t;
    }
    string getTopic(){return topic;}
    double getTuition(string status, int creditHours)override{
        if (status=="undergraduate"){
            return 200*creditHours;
        }
        else if(status=="graduate"){
            return 300*creditHours;
        }
        else if(status=="doctoral"){
            return 400*creditHours;
        }
        else {
            cout<<"incorrect status of student entered"<<endl;
            return 0.0;
        }
    }
    void display()const{
        cout<<"Research topic: "<<topic<<endl;
    }
};

int main(){
    GraduateStudent gs1;
    gs1.setTopic("Machine Learning");
    gs1.display();
    cout<<"Tuition: "<<gs1.getTuition("doctoral",240)<<endl;
    return 0;
}