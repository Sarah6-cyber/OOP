#include<iostream>
#include<string>
using namespace std;

class Car{
    int engine_horsepower, seating_capacity, speakers;
    public:
    Car(int h, int s, int p){
        engine_horsepower=h;
        seating_capacity=s;
        speakers=p;
    }
    Car change(int hp, int se, int sp)const{
        return Car(hp, se, sp);
    }
    void displayCar()const{
        cout<<"features: "<<endl;
        cout<<"Engine horspower: "<<engine_horsepower<<endl;
        cout<<"Seating Capacity: "<<seating_capacity<<endl;
        cout<<"Speakers: "<<speakers<<endl;
    }
};

int main(){
    Car c(100,10,5);
    cout<<"before modification of attributes"<<endl;
    c.displayCar();
    cout<<"after modification: "<<endl;
    c=c.change(300,6,8);
    c.displayCar();
    return 0;
}