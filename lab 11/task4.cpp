#include<iostream>
using namespace std;

template<typename T>
class Base{
protected:
    T a, b;
public:
    Base(T a, T b) : a(a), b(b){}
    void printProduct()const{
        cout << "Base product (a * b): " << a * b << endl;
    }
};

template<typename T>
class Derived : public Base<T>{
private:
    T c, d;
public:
    Derived(T a, T b, T c, T d) : Base<T>(a, b), c(c), d(d){}
    void printAllProducts()const{
        this->printProduct();
        cout << "Derived product (c * d): "<<c*d<<endl;
        T totalProduct=this->a*this->b*c*d;
        cout<<"Total product (a * b * c * d): "<<totalProduct<<endl;
    }
};

int main(){
    Derived<int>obj(2, 3, 4, 5);
    obj.printAllProducts();
    return 0;
}