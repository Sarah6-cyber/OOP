#include<iostream>
#include<string>
#include<iomanip>
using namespace std;

int main(){
    string Name;
    float Scores[5];
    float Avg, sum;
    cout<<"enter your name: "<<endl;
    getline(cin,Name);
    cout<<"enter scores for 5 tests: ";
    for (int i=0; i<5; i++){
        cin>>Scores[i];
        sum=sum+Scores[i];
    }
    Avg=sum/5;
    cout<<"Student Name: "<<Name<<endl;
    cout<<"Test Scores: ";
    cout<<fixed<<setprecision(2);
    for(int i=0; i<5; i++){
        cout<<Scores[i]<<" ";
    }
    cout<<endl<<"Average Test Score: "<<Avg;
    return 0;
}