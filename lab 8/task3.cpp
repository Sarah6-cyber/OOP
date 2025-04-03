#include<iostream>
#include<windows.h>
using namespace std;

class Currency{
    protected:
    double amount;
    string currencyCode;
    string currencySymbol;
    public:
    Currency(double amt, string code, string sym){
        amount=amt;
        currencyCode=code;
        currencySymbol=sym;
    }
    //base currency is Dollars (USD)
    virtual double convertToBase(){
        return amount/1.0;
    }    
    void convertTo(string targetCode){
        double base=convertToBase();
        if (targetCode=="USD"){
            cout<<""<<"Base Currency(USD) to "<<targetCode<<": $"<<base*1.0<<endl;
            return;
        }
        else if(targetCode=="EUR"){
            cout<<"Base Currency (USD) to "<<targetCode<<": \u20AC"<<base*0.93<<endl;
            return;
        }
        else if (targetCode=="PKR"){
            cout<<"Base Currency (USD) to "<<targetCode<<": Rs"<<base*276.89<<endl;
            return;
        }
        else {
            cout<<"invalid code entered. choose from (USD ,  EUR , PKR)"<<endl;
        }
    }
    virtual void displayCurrency(){
        cout<<currencySymbol<<amount<<"--> "<<currencyCode<<endl;
    }
};

class Dollar : public Currency{
    public:
    Dollar(double amt, string code, string sym) : Currency(amt,code,sym){}
    void displayCurrency()override{
        cout<<currencyCode<<": "<<currencySymbol<<amount<<endl;
    }
    double convertToBase()override{
        return amount/1.0;
    }  
};

class Euro : public Currency{
    public:
    Euro(double amt, string code, string sym) : Currency(amt,code,sym){}
    void displayCurrency()override{
        cout<<currencyCode<<": "<<currencySymbol<<amount<<endl;
    }
    double convertToBase()override{ 
        return amount/0.93;
    }  
};

class Rupee : public Currency{
    public:
    Rupee(double amt, string code, string sym) : Currency(amt,code,sym){}
    void displayCurrency()override{
        cout<<currencyCode<<": "<<amount<<" "<<currencySymbol<<endl;
    }
    double convertToBase()override{ 
        return amount/276.89;
    }
};

int main(){
    //for proper euro symbol output
    SetConsoleOutputCP(65001);

    Dollar usd(2000,"USD","$");
    Euro eur(3400.5,"EUR","\u20AC");
    Rupee pkr(5000,"PKR","Rs");

    usd.displayCurrency();
    pkr.displayCurrency();
    eur.displayCurrency();

    cout<<"Converting EUR to Base Currency...."<<endl;
    eur.convertTo("EUR");

    cout<<"Converting PKR to Base Currency...."<<endl;
    pkr.convertTo("USD");

    cout<<"Converting USD to Base Currency...."<<endl;
    usd.convertTo("PKR");

    return 0;
}