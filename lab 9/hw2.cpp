#include<iostream>
using namespace std;

class Car{
    protected:
    int model;
    double price;
    public:
    Car(){
        model=0;
        price=0.0;
    }
    int getModel(){return model;}
    double getPrice(){return price;}
    void setModel(int mod){
        model=mod;
    }
    virtual void setPrice(double pr)=0;
    virtual void display(){
        cout<<"Model: "<<model<<endl;
        cout<<"Price: "<<price<<endl;
    }
};

class Color : public Car{
    string color;
    public:
    Color(string c) : Car(){
        color=c;
    }
    void setPrice(double pr)override{
        price=pr+1000;
    }
    void display()override{
        cout<<"Model: "<<model<<endl;
        cout<<"Price: "<<price<<endl;
        cout<<"Color: "<<color<<endl;
    }
};

class Company : public Car{
    string company;
    public:
    Company(string c) : Car(){
        company=c;
    }
    void setPrice(double pr)override{
        double tax=pr*0.03;
        price=tax+pr;
    }
    void display()override{
        cout<<"Model: "<<model<<endl;
        cout<<"Price: "<<price<<endl;
        cout<<"Company: "<<company<<endl;
    }
};

int main(){
    Color cr("blue");
    Company cp("toyota");
    cr.setModel(2015);
    cr.setPrice(340000);
    cp.setModel(2021);
    cp.setPrice(820000);
    cr.display();
    cout<<"-----------------"<<endl;
    cp.display();
    return 0;
}
