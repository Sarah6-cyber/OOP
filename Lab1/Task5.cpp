#include<iostream>
#include<string>
#include<iomanip>
using namespace std;

int main(){
    int adult_t, child_t;
    float adult_p, child_p, gross_amt, donation_percent, donated_amt, net_sale;
    string movie;
    
    cout<<"enter movie name: "<<endl;
    getline(cin,movie);
    cout<<"enter number of adult tickets:"<<endl;
    cin>>adult_t;
    cout<<"enter price of 1 adult ticket:"<<endl;
    cin>>adult_p;
    cout<<"enter number of child tickets:"<<endl;
    cin>>child_t;
    cout<<"enter price of 1 child ticket:"<<endl;
    cin>>child_p;
    cout<<"enter percentage of donation you want to make:"<<endl;
    cin>>donation_percent;

    gross_amt=(adult_t*adult_p)+(child_t*child_p);
    donated_amt=(donation_percent/100)*gross_amt;
    net_sale=(gross_amt)-(donated_amt);

    cout<<"*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-"<<endl;
    cout<<"Movie Name:";
    cout<<right<<setw(28)<<movie<<endl;
    cout<<"Number of tickets sold: ";
    cout<<right<<setw(14)<<adult_t+child_t<<endl;
    cout<<fixed<<setprecision(2);
    cout<<"Gross Amount: ";
    cout<<right<<setw(25)<<gross_amt<<endl;
    cout<<"Percentage of Gross amount donated: ";
    cout<<donation_percent<<endl;
    cout<<"Amount Donated: ";
    cout<<right<<setw(23)<<donated_amt<<endl;
    cout<<"Net Sale: ";
    cout<<right<<setw(30)<<net_sale<<endl;
    return 0;
}
