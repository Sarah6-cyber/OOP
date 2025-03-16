#include<iostream>
using namespace std;

class Employee{
    protected:
    int ID;
    string name;
    public:
    Employee(int id, string n) : ID(id), name(n){}
    void displayEmployee(){
        cout<<"------Employee Info----------"<<endl;
        cout<<"Name: "<<name<<endl;
        cout<<"ID: "<<ID<<endl;
    }
};

class IOrderTaker{
    virtual void takeOrder(string order)=0;
};

class IBiller{
    virtual void generateBill(double amt)=0;
};

class IOrderPreparer{
    virtual void prepareOrder(string order)=0;
};

class Waiter : public Employee , public IOrderTaker{
    public:
    Waiter(int id, string n) : Employee(id,n){}
    void takeOrder(string order)override{
        cout<<"Waiter "<<name<<" taking order: "<<order<<endl;
    }
};

class Chef : public Employee , public IOrderPreparer{
    public:
    Chef(int id, string n) : Employee(id,n){}
    void prepareOrder(string order)override{
        cout<<"Chef "<<name<<" preparing order: "<<order<<endl;
    }
};

class Cashier : public Employee , public IBiller{
    public:
    Cashier(int id, string n) : Employee(id,n){}
    void generateBill(double amt)override{
        cout<<"Cashier "<<name<<" generating bill: $"<<amt<<endl;
    }
};

class Manager : public Employee, public IOrderTaker, public IBiller{
    public:
    Manager(int id, string n) : Employee(id,n){}
    void takeOrder(string order)override{
        cout<<"Manager "<<name<<" taking order: "<<order<<endl;
    }
    void generateBill(double amt)override{
        cout<<"Manager "<<name<<" generating bill: $"<<amt<<endl;
    }
};

class Menu{
    double *price;
    string *item;
    int itemCount;
    public:
    Menu(int count, string it[], double pr[]){
        itemCount=count;
        item=new string[itemCount];
        price=new double[itemCount];
        for (int i=0; i<itemCount; i++){
            item[i]=it[i];
            price[i]=pr[i];
        }
    }
    void displayMenu(){
        cout<<"--------MENU------------------------"<<endl;
        for (int i=0; i<itemCount; i++){
            cout<<"Item: "<<item[i]<<" |  price: $"<<price[i]<<endl;
        }
    }
    virtual void calculateTotalCost(double *priceOfOrderplaced, int countOfOrder)=0;
    ~Menu(){
        delete [] price;
        delete [] item;
    }
};

class FoodMenu : public Menu {
    public:
    FoodMenu(int count, string it[], double pr[]) : Menu(count, it, pr) {}
    void calculateTotalCost(double* priceOfOrderPlaced, int countOfOrder)override{
        double total=0;
        for (int i=0; i<countOfOrder; i++){
            total+=priceOfOrderPlaced[i];
        }
        cout<<"Total Cost of Food: $"<<total<<endl;
    }
};

class BeverageMenu : public Menu {
    public:
    BeverageMenu(int count, string it[], double pr[]) : Menu(count, it, pr) {}
    void calculateTotalCost(double* priceOfOrderPlaced, int countOfOrder)override{
        double total=0;
        for (int i=0; i<countOfOrder; i++){
            total+=priceOfOrderPlaced[i];
        }
        total*=1.20; //20% tax
        cout<<"Total Cost of Beverage: $"<<total<<endl;
    }
};

int main() {
    Waiter w(101, "Zaki");
    Chef c(102, "Aisha");
    Cashier cashier(103, "Zahra");
    Manager m(104, "Rowan");

    w.displayEmployee();
    c.displayEmployee();
    cashier.displayEmployee();
    m.displayEmployee();

    string foodItems[]={"Biryani","Mutton Karahi","BBQ"};
    double foodPrices[]={24.0,17.50,31.25};
    FoodMenu foodMenu(3,foodItems,foodPrices);

    string beverageItems[]={"Coke","Chai"};
    double beveragePrices[]={2.0,3.0};
    BeverageMenu beverageMenu(2, beverageItems, beveragePrices);

    foodMenu.displayMenu();
    beverageMenu.displayMenu();

    w.takeOrder("Pizza and BBQ and Coke");
    c.prepareOrder("Biryani");
    c.prepareOrder("BBQ");
    double foodOrderPrices[]={24.0,31.25};  
    double beverageOrderPrices[]={2.0}; 
    foodMenu.calculateTotalCost(foodOrderPrices,2);
    beverageMenu.calculateTotalCost(beverageOrderPrices,1);
    cashier.generateBill(24.0+31.25+0.2*1.20);
    return 0;
}
