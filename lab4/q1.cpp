#include<iostream>
#include<stdlib.h>
using namespace std;

class Circle{
    double radius;
    public:
    Circle(double r){
        radius=r;
    }
    double getArea(){
        return radius*radius*3.142;
    }
    double getPerimeter(){
        return 2*3.142*radius;
    }
};

int main(int argc, char *argv[]){
    if (argc<2){
        cout<<"too few arguments"<<endl;
    }
    Circle c(stod(argv[1]));
    c.getArea();
    c.getPerimeter();
    cout<<"Area: "<<c.getArea()<<endl;
    cout<<"Perimeter: "<<c.getPerimeter();
    return 0;
}