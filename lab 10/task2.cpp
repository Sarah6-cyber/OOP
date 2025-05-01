#include <fstream>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Employee
{
    int ID;
    int year;
    string name;
    string designation;

    void Data()
    {
        ofstream file("employee.txt");

        file << "1 jake Manager 2\n";
        file << "2 ben Engineer 1\n";
        file << "3 carlos HR 4\n";
        file << "4 damon Manager 4\n";
        file << "5 sofia Manager 3\n";
        file.close();
    }
};

void filtermanager()
{
    ifstream file("employee.txt");
    ofstream temp("filtered.txt");
    int ID;
    int year;
    string name;
    string designation;

    cout << "\nFiltered Managers with >= 2 years: \n";
    while (file >> ID >> name >> designation >> year)
    {
        if (designation == "Manager" && year >= 2)
        {
            cout << ID << " " << name << " " << designation << " " << year << endl;
            temp << ID << " " << name << " " << designation << " " << year << "\n";
        }
    }
    file.close();
    temp.close();
};

void keepFilteredOnly()
{
    ifstream filtered("filtered.txt");
    ofstream file("employee.txt");
    int ID, year;
    string name, designation;

    while (filtered >> ID >> name >> designation >> year)
    {
        file << ID << " " << name << " " << designation << " " << year << "\n";
    }

    filtered.close();
    file.close();
}

void IncrementedData()
{
    ifstream filtered("filtered.txt");
    ofstream file("employee.txt", ios::app); // append mode
    int ID, year;
    string name, designation;

    cout << "\nWriting incremented data:\n";
    while (filtered >> ID >> name >> designation >> year)
    {
        ID += 10;
        year += 1;
        cout << ID << " " << name << " " << designation << " " << year << endl;
        file << ID << " " << name << " " << designation << " " << year << "\n";
    }

    filtered.close();
    file.close();
}

int main()
{
    Employee emp;
    emp.Data();         // Write dummy data to file
    filtermanager();    // (a) Filter managers
    keepFilteredOnly(); // (b) Keep only filtered data
    IncrementedData();  // (c) Append incremented version

    return 0;
}