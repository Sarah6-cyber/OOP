#include<iostream>
using namespace std;

class Invoice{
    string num;
    string desc;
    int qtty;
    double price;
    public:
    Invoice(string n, string d, int q, double p){
        if (q<0){
            q=0;
        }
        if(p<0){
            p=0.0;
        }
        num=n;
        desc=d;
        qtty=q;
        price=p;
    }
    double getInvoiceAmount(int qtty, double price){
        double amt;
        amt=qtty*price;
        return amt;
    }
};

int main(){
    string number, description;
    int quantity;
    double price;
    cout<<"enter item number: "<<endl;
    cin>>number;
    cout<<"enter item description: "<<endl;
    cin>>description;
    cout<<"enter quantity of this item: "<<endl;
    cin>>quantity;
    cout<<"enter price per item: "<<endl;
    cin>>price;
    Invoice i1(number, description, quantity, price);
    cout<<"total amount: "<<i1.getInvoiceAmount(quantity, price)<<endl;
    return 0;
}