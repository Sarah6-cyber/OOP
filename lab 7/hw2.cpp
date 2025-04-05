#include<iostream>
using namespace std;

class Shape{
    float length, breadth;
    public:
    Shape(float l, float b){
        length=l;
        breadth=b;
    }
    float Area(){
        return length*breadth;
    }
    Shape operator+(Shape shape){
        float total=Area()+shape.Area();
        return Shape(total,1);
    }
    void displayArea(){
        cout<<"Area: "<<Area();
    }
};

int main(){
    Shape s1(3.5,7.2);
    Shape s2(4.0,8.5);
    cout<<"Area of shape 1: ";
    s1.displayArea();
    cout<<endl<<"Area of shape 2: ";
    s2.displayArea();
    Shape s3=s1+s2;
    cout<<endl<<"After Addition: "<<s3.Area();

}