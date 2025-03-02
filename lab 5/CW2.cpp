#include <iostream>
#include <vector>
using namespace std;

class Car{
    string name;
    int ID;
    public:
    Car(string n, int id){
        name=n;
        ID=id;
    }
    string getName()const{
        return name;
    }
    int getID()const{
        return ID;
    }
};

class Garage{
    vector<Car*>cars;
    public:
    void parkCar(Car* c) {
        cars.push_back(c);  
    }
    void listCar(){
        cout<<"Cars in garage: ";
        for (Car* c : cars) {
            cout<<c->getName()<<"  ";  
        }
        cout<<endl; 
    }
};

int main() {
    Car c1("Fortuner", 2005);
    Car c2("Prado", 2008);
    Car c3("Camaro ss", 2003);
    Garage garage;
    garage.parkCar(&c1);
    garage.parkCar(&c2);  
    garage.listCar(); 
    return 0;
}