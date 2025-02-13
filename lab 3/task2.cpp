#include<iostream>
using namespace std;

class Date{
    int year;
    int day;
    int month;
    public:
    void set_year(int y){
        year=y;
    }
    void set_month(int m){
        month=m;
    }
    void set_day(int d){
        day=d;
    }
    int get_year(){
        return year;
    }
    int get_month(){
        return month;
    }
    int get_day(){
        return day;
    }
    void DisplayDate(){
        cout<<month<<"/"<<day<<"/"<<year;
    }
};

int main(){
    Date t;
    t.set_month(2);
    t.set_day(10);
    t.set_year(25);
    t.DisplayDate();
    return 0;
}