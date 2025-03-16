#include<iostream>
using namespace std;

class Books{
    protected:
    string genre;
    public:
    Books(string g) : genre(g){}
};

class Mystery : public Books{
    protected:
    string title;
    string author;
    public:
    Mystery(string t, string a, string g) : Books(g){
        title=t;
        author=a;
    }
    void display(){
        cout<<"---------BOOK DETAILS--------------"<<endl;
        cout<<"Title: "<<title<<endl;
        cout<<"Author: "<<author<<endl;
        cout<<"Genre: "<<genre<<endl;
    }
};

class Fiction : public Books{
    protected:
    string title;
    string author;
    public:
    Fiction(string t, string a, string g) : Books(g){
        title=t;
        author=a;
    }
    void display(){
        cout<<"---------BOOK DETAILS--------------"<<endl;
        cout<<"Title: "<<title<<endl;
        cout<<"Author: "<<author<<endl;
        cout<<"Genre: "<<genre<<endl;
    }
};

int main(){
    Mystery a("Silent Patient","Alex Michaelidis","Psychological thriller");
    Fiction b("The Cruel Prince","Holly Black","Fantasy");
    a.display();
    cout<<endl;
    b.display();
    return 0;
}