#include<iostream>
using namespace std;

class MenuItem{
    string item_name, item_type;
    double price;
    public:
    MenuItem(){
        item_name="";
        item_type="";
        price=0.0;
    }
    MenuItem(string n, string t, double p){
        item_name=n;
        item_type=t;
        price=p;
    }
    string get_itemName(){
        return item_name;
    }
    string get_itemType(){
        return item_type;
    }
    double get_price(){
        return price;
    }
};

class CoffeeShop{
    string Name;
    MenuItem Menu[10];
    string orders[10];
    int count_m;
    int count_o;
    public:
    CoffeeShop(string n){
        Name=n;
        count_m=0;
        count_o=0;
    }
    string addOrder(string name_item){
        if (count_o>=10){
            cout<<"can't add orders. order full"<<endl;
        }
        for (int i=0; i<count_m; i++){
            if (Menu[i].get_itemName()==name_item){
                orders[count_o]=name_item;
                count_o++;
                return "order added successfully: "+name_item;
            }
        }
        return "this item is currently not available";
    }
    string fulfillOrder(){
        if (count_o>0){
            string item;
            item=orders[0];
            for (int i=0; i<count_o; i++){
                orders[i]=orders[i+1];
            }
            count_o--;
            return "the "+item+" is ready";
        }
        return "all orders fulfilled!";
    }
    void listOrders(){
        if(count_o==0){
            cout<<"no orders"<<endl;
            return;
        }
        cout<<"Current orders: ";
        for (int i=0; i<count_o; i++){
            cout<<orders[i]<<(i<count_o-1?", ":"");
        }
        cout<<endl;
    }
    void addMenu(string name, string type, double price){
        if(count_m<10){
            Menu[count_m]=MenuItem(name, type, price);
            count_m++;
        }else{
            cout<<"can't add items, menu full!"<<endl;
        }
    }
    double dueAmount(){
        double amt=0.0;
        for (int i=0; i<count_o; i++){
            for (int j=0; j<count_m; j++){
                if (orders[i]==Menu[j].get_itemName()){
                    amt+=Menu[j].get_price();
                }
            }
        }
        return amt;
    }
    string cheapestItem(){
        if (count_m == 0) return "Menu is empty!";
        
        int min= 0;
        for (int i=1; i<count_m; i++){
            if (Menu[i].get_price()<Menu[min].get_price()){
                min=i;
            }
        }
        return Menu[min].get_itemName();
    }
    void drinksOnly(){
        cout<<"Drinks available: ";
        for (int i=0; i<count_m; i++){
            if (Menu[i].get_itemType()=="drink"){
                cout<<Menu[i].get_itemName()<<" ";
            }
        }
        cout<<endl;
    }
    void foodOnly(){
        cout<<"Food available: ";
        for (int i=0; i<count_m; i++){
            if (Menu[i].get_itemType()=="food"){
                cout<<Menu[i].get_itemName()<<" ";
            }
        }
        cout<<endl;
    }
};

int main(){
    CoffeeShop shop("Cafe Castillo");
    shop.addMenu("Mocha", "drink", 5.50);
    shop.addMenu("Latte", "drink", 3.00);
    shop.addMenu("Cappuccino", "drink", 7.50);
    shop.addMenu("Muffin", "food", 6.50);
    shop.addMenu("Waffles", "food", 5.00);
    cout<<shop.addOrder("Mocha")<<endl;
    cout<<shop.addOrder("Shawarma")<<endl;
    cout<<"our cheapest item: "<<shop.cheapestItem()<<endl;
    shop.listOrders();
    shop.foodOnly();
    shop.drinksOnly();
    return 0;
}