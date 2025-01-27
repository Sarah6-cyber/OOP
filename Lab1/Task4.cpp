#include<iostream>
#include<iomanip>
using namespace std;

int main(){
    float in_kgs;
    cout<<"enter your weight in kilograms: ";
    cin>>in_kgs;
    float in_pounds;
    in_pounds=in_kgs*2.2;
    cout<<fixed<<setprecision(2);
    cout<<"weight in kgs: "<<in_kgs<<endl;
    cout<<"weight in pounds: "<<in_pounds<<endl;
    return 0;
}