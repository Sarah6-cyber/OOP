#include <iostream>
#include <string>
using namespace std;

class Book{
    string author, title, publisher;
    double price;
    int stock;
public:
    Book(){
        stock=0;
        price=0.0;
        author="";
        title="";
        publisher="";
    }
    Book(string a, string t, string u, double p, int o) {
        author=a;
        title=t;
        publisher=u;
        price=p;
        stock=o;
    }
    string getAuthor(){ 
        return author; 
    }
    string getTitle(){ 
        return title; 
    }
    string getPublisher(){
     return publisher; 
    }
    double getPrice(){ 
        return price; 
    }
    int getStock(){ 
        return stock; 
    }
    bool searchBook(string a, string t){
        return t==title && a==author;
    }
    void details(){
        cout<<"Details of this book: "<<endl;
        cout<<"Title: "<<title<<endl;
        cout<<"Author: "<<author<<endl;
        cout<<"Publisher: "<<publisher<<endl;
        cout<<"Price per book: "<<price<<endl;
        cout<<"Copies in stock: "<<stock<<endl;
    }
    void bookValues(string t, string a, string p, int s, double r) {
        title=t;
        author=a;
        publisher=p;
        stock=s;
        price=r;
    }
    void purchaseBook(int num) {
        double amt;
        if (stock>=num) {
            amt=num*price;
            stock-=num;
            cout<<"Total Amount for "<<num<<" books: "<<amt<< endl;
        } else{
            cout<<"Required copies not in stock"<<endl;
        }
    }
};
void addBook(Book books[], int &count){
    if (count>=10){
        cout<<"can't add more books! Inventoryu is full"<<endl;
        return;
    }
    string auth, title, publ;
    int sto;
    double pri;
    cin.ignore();
    cout<<"Enter book title: ";
    getline(cin, title);
    cout<<"Enter author name: ";
    getline(cin, auth);
    cout<<"Enter publisher: ";
    getline(cin, publ);
    cout<<"Enter copies of books: ";
    cin>>sto;
    cout<<"Enter price per book: ";
    cin>>pri;
    books[count]=Book(auth, title, publ, pri, sto);
    count++;
    cout<<"Book added successfully!\n";
}

int main(){
    int choice, num, found;
    string search_t, search_a;
    int bookCount = 3;
    Book books[10];
    books[0]=Book("J.K. Rowling", "Harry Potter", "Bloomsbury", 200.0, 8);
    books[1]=Book("Alex Michaelidis", "Silent Patient", "Celadon Books", 600.0, 5);
    books[2]=Book("George Orwell", "1984", "Secker & Warburg", 300.0, 5);
    do {
        cout<<"Welcome to Bookshop "<<endl;
        cout<<"1.Add Book"<<endl;
        cout<<"2.Search and Buy Book"<<endl;
        cout<<"3.Exit"<<endl;
        cout<<"Enter your choice: ";
        cin>>choice;
        switch (choice){
            case 1:
                addBook(books, bookCount);
                break;
            case 2:
                cin.ignore();
                cout<<"Enter book title: ";
                getline(cin, search_t);
                cout<<"Enter author name: ";
                getline(cin, search_a);
                found=0;
                for (int i=0; i<bookCount; i++){
                    if (books[i].searchBook(search_a, search_t)) {
                        cout<<"Book found!"<<endl;
                        books[i].details();
                        cout<<"Enter number of copies you want: ";
                        cin>>num;
                        books[i].purchaseBook(num);
                        found=1;
                        break;
                    }
                }
                if (!found) {
                    cout<<"Book not found in inventory."<<endl;
                }
                break;
            case 3:
                break;
            default:
                cout<<"Invalid choice! Please enter a valid option."<<endl;
        }
    } while (choice != 3);
    return 0;
}
