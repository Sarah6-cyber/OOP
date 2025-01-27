#include<iostream>
using namespace std;
 int main(){
    int array[50];
    int sum=0;
    int size;
    cout<<"enter the count of numbers you will enter (range: 2-50): "<<endl;
    cin>>size;
    cout<<"enter the numbers: ";
    for (int i=0; i<size; i++){
        cin>>*(array+i);
        sum=sum+*(array+i);
    }
    cout<<"the sum of entered numbers is: "<<sum<<endl;
    return 0;
 }