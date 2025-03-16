#include<iostream>
using namespace std;

class Vehicles{
    protected:
    double price;
    public:
    Vehicles(double p) : price(p){}
};

class Car : public Vehicles{
    protected:
    int capacity;
    int doorCount;
    string fuelType;
    public:
    Car(int c, int d, string f, double p) : Vehicles(p){
        capacity=c;
        doorCount=d;
        fuelType=f;
    }
};

class Motorcycle : public Vehicles{
    protected:
    int cylinderCount;
    int gearCount;
    int wheelCount;
    public:
    Motorcycle(int c, int g, int w, double p) : Vehicles(p){
        cylinderCount=c;
        gearCount=g;
        wheelCount=w;
    }
};

class Audi : public Car{
    string modelType;
    public:
    Audi(double p, int c, int d, string f, string m) : Car(c,d,f,p){
        modelType=m;
    }
    void display(){
        cout<<"--------CAR DETAILS------------------"<<endl;
        cout<<"Price: $"<<price<<endl;
        cout<<"Seating Capacity: "<<capacity<<endl;
        cout<<"Number of Doors: "<<doorCount<<endl;
        cout<<"Fuel Type: "<<fuelType<<endl;
        cout<<"Model Type: "<<modelType<<endl;
    }
};

class Yamaha : public Motorcycle{
    string makeType;
    public:
    Yamaha(int c, int g, int w, double p, string m) : Motorcycle(c,g,w,p){
        makeType=m;
    }
    void display(){
        cout<<"-------Motorcycle Details------------"<<endl;
        cout<<"Price: $"<<price<<endl;
        cout<<"Number of Cylinders: "<<cylinderCount<<endl;
        cout<<"Number of Gears: "<<gearCount<<endl;
        cout<<"Number of Wheels: "<<wheelCount<<endl;
        cout<<"Make-Type: "<<makeType<<endl;
    }
};

int main(){
    Audi a1(95000,5,4,"Petrol","Audi A6");
    Yamaha y1(4,6,2,30000,"Sports");
    a1.display();
    cout<<endl;
    y1.display();
    return 0;
}