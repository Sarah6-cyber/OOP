#include <fstream>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Structs for schema
struct User {
    string user_id, first_name, last_name, address, email;
};

struct Product {
    string product_id, product_name, description;
    int price;
};

struct Order {
    string order_id, user_id, product_id;
    int total_paid;
};

// Function to write dummy data
void writeDummyData() {
    ofstream users("users.txt");
    users << "u1,Linus,Torvalds,Finland,linus@example.com\n";
    users << "u2,Ada,Lovelace,UK,ada@example.com\n";
    users.close();

    ofstream products("products.txt");
    products << "p1,Laptop,High-performance laptop,1500\n";
    products << "p2,Mouse,Wireless mouse,50\n";
    products << "p3,Monitor,24 inch monitor,200\n";
    products.close();

    ofstream orders("orders.txt");
    orders << "o1,u1,p1,1500\n";
    orders << "o2,u1,p2,50\n";
    orders << "o3,u2,p3,200\n";
    orders.close();
}

// Function to get user_id from name
string getUserIdByName(const string& targetName) {
    ifstream file("users.txt");
    string line;
    while (getline(file, line)) {
        vector<string> parts;
        string temp = "";
        for (char c : line) {
            if (c == ',') {
                parts.push_back(temp);
                temp = "";
            } else {
                temp += c;
            }
        }
        parts.push_back(temp); // last field

        if (parts.size() >= 2 && parts[1] == targetName) {
            return parts[0]; // user_id
        }
    }
    return "";
}

string getProductNameById(const string& product_id) {
    ifstream file("products.txt");
    string line;
    while (getline(file, line)) {
        vector<string> parts;
        string temp = "";
        for (char c : line) {
            if (c == ',') {
                parts.push_back(temp);
                temp = "";
            } else {
                temp += c;
            }
        }
        parts.push_back(temp);

        if (parts.size() >= 2 && parts[0] == product_id) {
            return parts[1]; // product_name
        }
    }
    return "";
}

void queryProductsByUserName(const string& name) {
    string user_id = getUserIdByName(name);
    if (user_id == "") {
        cout << "User not found.\n";
        return;
    }

    ifstream file("orders.txt");
    string line;
    cout << "Products ordered by " << name << ":\n";
    while (getline(file, line)) {
        vector<string> parts;
        string temp = "";
        for (char c : line) {
            if (c == ',') {
                parts.push_back(temp);
                temp = "";
            } else {
                temp += c;
            }
        }
        parts.push_back(temp);

        if (parts.size() >= 3 && parts[1] == user_id) {
            string product_name = getProductNameById(parts[2]);
            cout << "- " << product_name << "\n";
        }
    }
}

int main() {
    writeDummyData(); // Create dummy data
    queryProductsByUserName("Linus"); // Fetch product names for Linus
    return 0;
}