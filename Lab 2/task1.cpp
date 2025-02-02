#include<iostream>
using namespace std;
int main(int argc, char *argv[]){
    int sum=0;
    if (argc<2){
        cout<<"too less numbers! cant sum"<<endl;
        return 1;
    }
    for (int i=1; i<argc; i++){
        sum+=atoi(*(argv+i));
    }
    cout<<"the sum is "<<sum<<endl;
    return 0;
}