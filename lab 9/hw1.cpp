#include<iostream>
using namespace std;

class Shape{
    public:
    virtual float getArea()=0;
};

class Rectangle : public Shape{
    float breadth, length;
    public:
    Rectangle(float l, float b) : breadth(b) , length(l) {}
    float getArea(){
        return length*breadth;
    }
};

class Triangle : public Shape{
    float base, height;
    public:
    Triangle(float h, float b) : base(b) , height(h) {}
    float getArea(){
        return 0.5*base*height;
    }
};

int main(){
    Rectangle r(10,5.5);
    Triangle t(4.2,3.6);
    cout<<"Area of triangle: "<<t.getArea()<<endl;
    cout<<"Area of rectangle: "<<r.getArea()<<endl;
    return 0;
}