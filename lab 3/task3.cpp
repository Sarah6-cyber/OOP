#include<iostream>
using namespace std;

class Glass{
    public:
    int liquidLevel;
    void publicDrink(int d){
        int drank=d;
        liquidLevel-=d;
    }
    void publicRefill(){
        if (liquidLevel<100){
            liquidLevel=200;
            cout<<"glass refilled to 200!"<<endl;
        }
    }
};

int main(){
    int choice;
    int amt;
    Glass g1;
    g1.liquidLevel=200;
    for( ;choice!=3; ){
        cout<<"enter option number to proceed"<<endl;
        cout<<"1. Amount in glass"<<endl;
        cout<<"2. Drink from glass"<<endl;
        cout<<"3. End program"<<endl;
        cin>>choice;
        if (choice==3){
            return 1;
        }
        if (choice==1){
            cout<<g1.liquidLevel<<endl;
        }
        if (choice==2){
            cin.ignore();
            cout<<"enter amount you drank: ";
            cin>>amt;
            g1.publicDrink(amt);
            g1.publicRefill();
        }
    }
    return 0;
}