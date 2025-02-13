#include<iostream>
#include<string>
using namespace std;

class Book{
    string name;
    string ISBN;
    string author;
    string publisher;
    public:
    Book(){

    }
    Book(string name, string ISBN, string author, string publisher){
        this->name=name;
        this->ISBN=ISBN;
        this->author=author;
        this->publisher=publisher;
    }
    string get_name(){
        return this->name;
    }
    string get_ISBN(){
        return this->ISBN;
    }
    string get_author(){
        return this->author;
    }
    string get_publisher(){
        return this->publisher;
    }
    void getBook(){
        cout<<"Name: "<<this->name<<endl;
        cout<<"ISBN: "<<this->ISBN<<endl;
        cout<<"Author: "<<this->author<<endl;
        cout<<"Publisher: "<<this->publisher<<endl;
    }
};

int main(int argc, char *argv[]){
    Book book[5];
    int count=1;
    for (int i=0; i<5; i++){
        book[i]=Book(argv[count],argv[count+1],argv[count+2],argv[count+3]);
        count+=4;
    }
    for (int i=0; i<5; i++){
        cout<<"Book "<<i+1<<endl;
        book[i].getBook();
    }
    return 0;
}