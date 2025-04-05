#include<iostream>
using namespace std;

class Value{
    int val;
    public:
    Value(int v) : val(v){}
    //prefix
    Value operator--(){
        val*=4;
        return *this;
    }
    //postfix
    Value operator--(int){
        Value temp=val;
        val/=4;
        return temp;
    }
    void displayValue()const{
        cout<<val<<endl;
    }
};

int main(){
    Value v1(2);
    cout<<"Original Number: ";
    v1.displayValue();
    --v1;
    cout<<"After prefix: ";
    v1.displayValue();
    v1--;
    cout<<"After postfix: ";
    v1.displayValue();
    return 0;
}