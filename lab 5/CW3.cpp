#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Catalog {
    vector<string> ISBN;      
    vector<string> locations; 
    
public:
    void addISBN(string s, string l) {
        ISBN.push_back(s);         
        locations.push_back(l);    
        cout << "\nISBN Added: " << s << " at location " << l;
    }

    string getLocation(string isbn) {
        for (size_t i = 0; i < ISBN.size(); ++i) {
            if (isbn == ISBN[i]) {
                return locations[i];
            }
        }
        return "Book not found in record"; 
    }
};

class Book {
    string title;
    string author;
    string isbn;

public:
    Book(string t, string a, string i) : title(t), author(a), isbn(i) {}

    string getTitle() const {
        return title;
    }

    string getAuthor() const {
        return author;
    }

    string getISBN() const {
        return isbn;
    }
};

class Library {
    Catalog catalog; 
    vector<Book> books; 

public:
    void addBook(const Book& book, string location) {
        catalog.addISBN(book.getISBN(), location); 
        books.push_back(book); 
    }

    void searchBookByISBN(string isbn) {
        string location = catalog.getLocation(isbn);
        if (location != "ISBN not found") {
            cout << "Book found at location: " << location << endl;
        } else {
            cout << "Book with ISBN " << isbn << " not found." << endl;
        }
    }

    void printLibraryBooks() {
        for (const auto& book : books) {
            cout << "Book: " << book.getTitle() << ", Author: " << book.getAuthor() << ", ISBN: " << book.getISBN() << endl;
        }
    }
};

int main() {
    Library myLib;
    Book book1("The Silent Patient", "Alex Michaelidis", "987456321");
    Book book2("AGGTM", "Holly Jackson", "123456789");
    Book book3("A thousand Splendid Suns", "Khaleid Hosseini", "9780061120084");
    myLib.addBook(book1, "A1");
    myLib.addBook(book2, "B1");
    myLib.addBook(book3, "C1");
    cout << "\nBooks in the library:\n";
    myLib.printLibraryBooks();
    cout<<"Searching for book with ISBN 9780451524935..."<<endl;
    myLib.searchBookByISBN("9780451524935");
    cout<<"Searching for book with ISBN 0000000000000..."<<endl;
    myLib.searchBookByISBN("0000000000000");
    return 0;
}