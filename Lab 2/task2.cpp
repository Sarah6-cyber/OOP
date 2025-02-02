#include<iostream>
using namespace std;

void* addToEachElement(int size, void* array){
    int *arr=(int*)array;
    for (int i=0; i<size; i++){
        arr[i]+=10;
    }
    return (void*)arr;
}
    
int main(int argc, char *argv[]){
    if (argc<2){
        cout<<"too few inputs"<<endl;
        return 1;
    }
    int count=argc-1;
    int *array=new int[count]; 
    for (int i=0; i<count; i++){
        array[i]=atoi(argv[i+1]);
    }
    array=(int*)addToEachElement(count,array);
    cout<<"after increment of 10: "<<endl;
    for (int i=0; i<count; i++){
        cout<<array[i]<<" ";
    }
    return 0;
}