#include<iostream>
const int sizeOfLib=8;
using namespace std;

class Media{
    protected:
    string title, publicationDate, publisher;
    int uniqueID;
    public:
    Media(int id, string t, string d, string p){
        uniqueID=id;
        publicationDate=d;
        publisher=p;
        title=t;
    }
    virtual void displayInfo(){
        cout<<"-------Media Details-------"<<endl;
        cout<<"Title: "<<title<<endl;
        cout<<"Publication date: "<<publicationDate<<endl;
        cout<<"ID: "<<uniqueID<<endl;
        cout<<"publisher: "<<publisher<<endl;
    }
    void checkOut(){
        cout<<"lending in process..."<<endl;
    }
    Media returnItem(){
        cout<<"item returned"<<endl;
    }
    int getID(){return uniqueID;}
    string getTitle(){return title;}
};

class Book : public Media{
    int pages;
    string author, ISBN;
    public:
    Book(int id, string t, string d, string p, string aut, string isbn, int pageCount) : Media(id,t,d,p){
        author=aut;
        ISBN=isbn;
        pages=pageCount;
    }
    void displayInfo()override{
        cout<<"-------Book Details-------"<<endl;
        cout<<"Title: "<<title<<endl;
        cout<<"Publication date: "<<publicationDate<<endl;
        cout<<"ID: "<<uniqueID<<endl;
        cout<<"Publisher: "<<publisher<<endl;
        cout<<"Author: "<<author<<endl;
        cout<<"ISBN: "<<ISBN<<endl;
        cout<<"Number of pages: "<<pages<<endl;
    }
};

class DVD : public Media{
    string director, duration;
    float rating;
    public:
    DVD(int id, string t, string d, string p, string dir, string dur, float r) : Media(id,t,d,p){
        rating=r;
        director=dir;
        duration=dur;
    }
    void displayInfo()override{
        cout<<"-------DVD Details-------"<<endl;
        cout<<"Title: "<<title<<endl;
        cout<<"Publication date: "<<publicationDate<<endl;
        cout<<"ID: "<<uniqueID<<endl;
        cout<<"Publisher: "<<publisher<<endl;
        cout<<"Director: "<<director<<endl;
        cout<<"Duration: "<<duration<<endl;
        cout<<"Rating: "<<rating<<endl;
    }
};

class CD : public Media{
    string artist, genre;
    int trackCount;
    public:
    CD(int id, string t, string d, string p, string art, string g, int tracks) : Media(id,t,d,p){
        artist=art;
        genre=g;
        trackCount=tracks;
    }
    void displayInfo()override{
        cout<<"-------CD Details-------"<<endl;
        cout<<"Title: "<<title<<endl;
        cout<<"Publication date: "<<publicationDate<<endl;
        cout<<"ID: "<<uniqueID<<endl;
        cout<<"Publisher: "<<publisher<<endl;
        cout<<"Artist: "<<artist<<endl;
        cout<<"Genre: "<<genre<<endl;
        cout<<"Number of tracks: "<<trackCount<<endl;
    }
};

class Magazine : public Media{
    public:
    Magazine(int id, string t, string d, string p) : Media(id,t,d,p){}
    void displayInfo(){
        cout<<"-------Magazine Details-------"<<endl;
        cout<<"Title: "<<title<<endl;
        cout<<"Publication date: "<<publicationDate<<endl;
        cout<<"ID: "<<uniqueID<<endl;
        cout<<"publisher: "<<publisher<<endl;
    }
};

void searchByID(Media* l[], int count, int id) {
    for (int i=0; i<count; i++){
        if (l[i] && l[i]->getID()==id){
            cout<<"Media found: "<<endl;
            l[i]->displayInfo();
            return;
        }
    }
    cout<<"Media with ID "<<id<<" not found"<<endl;
}

void searchByTitle(Media* library[], int size, string title){
    bool found=false;
    for (int i=0; i<size; i++){
        if (library[i] && library[i]->getTitle()==title){
            cout<<"Media found: ";
            library[i]->displayInfo();
            found=true;
        }
    }
    if (found==false){
        cout<<"No media found with title: "<<title<<endl;
    }
}

int main() {
    Media* library[sizeOfLib]={nullptr};
    int count=0;
    library[count++]=new Book(101, "The Great Gatsby", "1925", "Scribner", "F. Scott Fitzgerald", "9780743273565", 180);
    library[count++]=new DVD(202, "Inception", "2010", "Warner Bros.", "Christopher Nolan", "2.8 hrs", 8.8);
    library[count++]=new CD(303, "Thriller", "1982", "Epic Records", "Michael Jackson", "Pop",9);
    library[count++]=new Magazine(404, "National Geographic", "2023", "NatGeo");

    cout<<"------Current Media Collection--------"<<endl;
    for (int i=0; i<count; i++){
        if (library[i]){
            library[i]->displayInfo();
        }
    }
    searchByID(library, count, 202);
    searchByTitle(library, count, "Thriller");

    for (int i=0; i<count; i++){
        delete library[i];
    }
    return 0;
}