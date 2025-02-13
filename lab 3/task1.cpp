#include<iostream>
using namespace std;

class User{
    public:
    string Name;
    int Age;
};

int main(){
    User u;
    u.Age=24;
    u.Name="Teo";
    cout<<"My name is "<<u.Name<<" and I'm "<<u.Age<<" years old.";
    return 0;
}