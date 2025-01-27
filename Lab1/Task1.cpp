#include<iostream>
using namespace std;

int main(){
    float array[20];
    int size=20;
    for (int i=0; i<size; i++){
        cin>>*(array+i);
    }
    float highest=*array;
    float sec_highest=*array;
    for (int i=0; i<size; i++){
        if (*(array+i)>highest){
            sec_highest=highest;
            highest=*(array+i);
        }
    }
    cout<<"the second highest num is "<<sec_highest<<endl;
    return 0;
}
