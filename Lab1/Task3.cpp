#include<iostream>
#include<string>
using namespace std;

float calculateBill(int units){
    float bill;
    if (units<=199){
        bill=units*16.20;
    }
    else if (units<300){
        bill=20.10*(units);
    }
    else if (units<500){
        bill=27.10*(units);
    }
    else if (units>=500){
        bill=35.90*(units);
    }
    if (bill>18000){
        float surcharge=bill*0.15;
        bill=bill+surcharge;
    }
    return bill;
}

int main(){
    string Name;
    int ID;
    int units;
    cout<<"enter your name: ";
    cin>>Name;
    cout<<"enter your ID: ";
    cin>>ID;
    cout<<"enter units consumed: ";
    cin>>units;
    cout<<"Customer ID: "<<ID<<endl;
    cout<<"Customer name: "<<Name<<endl;
    cout<<"Units consumed: "<<units<<endl;
    cout<<"Amount to be paid: "<<calculateBill(units);
    return 0;
}