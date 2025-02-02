#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

struct Student
{
    string name;
    int id;
};

bool sortByID(Student s1, Student s2){
    if (s1.id!=s2.id){
        return s1.id<s2.id;
    }
    else {
        return s1.name<s2.name;
    }
}
bool sortByName(Student s1, Student s2){
    return s1.name<s2.name;
}

int main(){
    int n;
    cout<<"enter the number of \"struct Student\" you want to make: ";
    cin>>n;
    Student array[20];
    for (int i=0; i<n; i++){
        cout<<"enter for Student "<<i+1<<endl;
        cout<<"ID: ";
        cin>>array[i].id;
        cin.ignore();
        cout<<"Name: ";
        getline(cin, array[i].name);
    }
    sort(array,array+n,sortByID);
    cout<<"sort by ID"<<endl;
    for (int i=0; i<n; i++){
        cout<<"ID: "<<array[i].id<<"  "<<"Name: "<<array[i].name<<endl;
    }
    sort(array,array+n,sortByName);
    cout<<"sort by Name"<<endl;
    for (int i=0; i<n; i++){
        cout<<"Name: "<<array[i].name<<"  "<<"ID: "<<array[i].id<<endl;
    }
    return 0;
}