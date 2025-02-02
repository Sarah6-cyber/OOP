#include<iostream>
using namespace std;

int main(){
    int size=5;
    int *array=new int[size];
    int i=0;
    cout<<"enter numbers (if you want to stop, enter 0): "<<endl;
    for ( ; ; i++){
        if (i>=size){
            size=size*2;
            int *new_arr=new int[size];
            for (int j=0; j<size/2; j++){
                new_arr[j]=array[j];
            }
            delete[] array;
            array=new_arr;
            cout<<"memory doubled to size "<<size<<endl;
        }
        cin>>array[i];
        if (array[i]==0){
            break;
        }
    }
    int *resized_array=new int[i];
    for (int j=0; j<i; j++){
        resized_array[j]=array[j];
    }
    cout<<"after resizing the array"<<endl;
    for (int k=0; k<i; k++){
        cout<<resized_array[k]<<" ";
    }
    delete[] array;
    delete[] resized_array;
    return 0;
}
