#include<iostream>
using namespace std;

class Shape{
    int position;
    string colour;
    float borderThickness;
    public:
    Shape(int pos, string col, float border){
        position=pos;
        colour=col;
        borderThickness=border;
    }
    virtual void draw(){
        cout<<"drawing a shape..."<<endl;
    }
    virtual float calculateArea(){
        return 0.0;
    }
    virtual float calculatePerimeter(){
        return 0.0;
    }
    virtual void display(){
        cout<<"Area: "<<calculateArea()<<endl;
        cout<<"Perimeter: "<<calculatePerimeter()<<endl;
    }
};

class Circle : public Shape{
    float radius;
    int center;
    public:
    Circle(int r, int c, int pos, string col, float border) : Shape(pos,col,border){
        radius=r;
        center=c;
    } 
    void draw()override{
        cout<<"i am drawing a circle"<<endl;
    }
    float calculateArea()override{
        return 3.142*radius*radius;
    }
    float calculatePerimeter()override{
        return 2*3.142*radius;
    }
    void display()override{
        cout<<"-----A Circle----------------"<<endl;
        cout<<"Area: "<<calculateArea()<<endl;
        cout<<"Perimeter: "<<calculatePerimeter()<<endl;
    }
};

class Rectangle : public Shape{
    float width, height;
    int topleft_position;
    public:
    Rectangle(float w, float h, int top, int pos, string col, float border) : Shape(pos,col,border){
        width=w;
        height=h;
        topleft_position=top;
    }
    void draw()override{
        cout<<"i am drawing a rectangle"<<endl;
    }
    float calculateArea()override{
        return width*height;
    }
    float calculatePerimeter()override{
        return (2*width)+(2*height);
    }
    void display()override{
        cout<<"-----A Rectangle----------------"<<endl;
        cout<<"Area: "<<calculateArea()<<endl;
        cout<<"Perimeter: "<<calculatePerimeter()<<endl;
    }
};

class Triangle : public Shape{
    float base, height, side_a, side_b;
    public:
    Triangle(float a, float sb, float b, float h, int pos, string col, float border) : Shape(pos,col,border){
        base=b;
        height=h;
        side_a=a;
        side_b=sb;
    }
    void draw()override{
        cout<<"i am drawing a triangle"<<endl;
    }
    float calculateArea()override{
        return (1/2)*base*height;
    }
    float calculatePerimeter()override{
        return side_a+base+side_b;
    }
    void display()override{
        cout<<"-----A Triangle----------------"<<endl;
        cout<<"Area: "<<calculateArea()<<endl;
        cout<<"Perimeter: "<<calculatePerimeter()<<endl;
    }
};

class Polygon : public Shape{
    float apothem;
    int sideCount;
    float side_length;
    public:
    Polygon(int pos, string col, float border, float ap, int sidesNum,float length) : Shape(pos,col,border){
        apothem=ap;
        sideCount=sidesNum;
        side_length=length;
    }
    void draw()override{
        cout<<"I am drawing a polygon"<<endl;
    }
    float calculatePerimeter()override{
        return sideCount*side_length;
    }
    float calculateArea(){
        return calculatePerimeter()*apothem*0.5;
    }
    void display()override{
        cout<<"-----A Polygon----------------"<<endl;
        cout<<"Area: "<<calculateArea()<<endl;
        cout<<"Perimeter: "<<calculatePerimeter()<<endl;
    }
};

int main(){
    Circle c(5, 10, 1, "Red", 2.5);
    c.draw();
    c.display();    
    cout << endl;

    Rectangle r(4, 6, 2, 2, "Blue", 1.5);
    r.draw();
    r.display();
    cout << endl;

    Triangle t(3, 4, 5, 6, 3, "Green", 1.0);
    t.draw();
    t.display();
    cout << endl;

    Polygon p(4, "Yellow", 2.0, 5, 6, 4);
    p.draw();
    p.display();
    
    return 0;
}


