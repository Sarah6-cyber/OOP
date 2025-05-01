#include<fstream>
#include<iostream>
#include<string>
using namespace std;

string Encryption(string input){
    for (int i = 0; i < input.length(); i++)
    {
        input[i]+=i+1;
    }
    return input;
}

string Decryption(string input){
    for (int i = input.length(); i > 0; i--)
    {
        input[i-1]-=i;
    }
    return input;
}

int main(){
    ofstream file("Task.txt");
    string input;
    cout<<"Enter input: ";
    cin>>input;

    file<<Encryption(input);
    cout<<Encryption(input)<<endl;
    file.close();

    string input1;
    ifstream file1("Task.txt");
    while(getline(file1, input1)){
    };
    file1.close();
    Decryption(input1);
    cout<<Decryption(input1);

    return 0;
}