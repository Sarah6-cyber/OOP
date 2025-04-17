#include<iostream>
using namespace std;

class Passenger;

class Flight{
    string flightNumber, departure, arrival;
    int capacity, bookedCount;
    Passenger **passengers;
    friend class Passenger;
    public:
    Flight(string num, string dep, string arr, int cap){
        flightNumber=num;
        departure=dep;
        arrival=arr;
        capacity=cap;
        bookedCount=0;
        passengers=new Passenger*[capacity];
        for (int i=0; i<capacity; i++){
            passengers[i]=nullptr;
        }
    }
    void showFlightDetails();
    void showPassengers();
    void bookSeat(Passenger *p){
        if (bookedCount>=capacity){
            cout<<"cant add more passengers. seats already booked"<<endl;
            return;
        }
        for (int i=0; i<capacity; i++){
            if(passengers[i]==nullptr){
                passengers[i]=p;
                bookedCount++;
                cout<<"seat booked for passenger"<<endl;
                return;
            }
        }
    }
    void cancelSeat(Passenger *p){
        bool found=false;
        for (int i=0; i<capacity; i++){
            if (passengers[i]==p){
                bookedCount--;
                cout<<"seat for passenger cancelled"<<endl;
                found=true;
                break;
            }
        }
        if (!found){
            cout<<"cant find passenger"<<endl;
        }
    }
    void upgradeSeat(Passenger *p);
    ~Flight(){
        delete [] passengers;
    }
};

class Passenger{
    string name;
    int ID;
    bool booked;
    friend class Flight;
    public:
    Passenger(string n, int id){
        booked=false;
        name=n;
        ID=id;
    }
    void requestBooking(Flight &f){
        if (booked){
            cout<<"Passenger already booked"<<endl;
        }
        else {
            f.bookSeat(this);
            booked=true;
        }
    }
    void requestCancelling(Flight &f){
        if (booked){
            f.cancelSeat(this);
            booked=false;
        }
        else {
            cout<<"flight not booked at the moment"<<endl;
        }
    }
    void requestUpgrading(Flight &f){
        if (booked){
            f.upgradeSeat(this);
        }
    }
};

void Flight::upgradeSeat(Passenger *p){
    cout<<"seat upgraded for passenger "<<p->name<<endl;
}

void Flight::showFlightDetails(){
    cout<<"-------Flight Details------------"<<endl;
    cout<<"Flight number: "<<flightNumber<<endl;
    cout<<"Departure: "<<departure<<endl;
    cout<<"Arrival: "<<arrival<<endl;
    cout<<"Capacity: "<<capacity<<endl;
}

void Flight::showPassengers(){
    cout<<"-------Booked Passengers--------"<<endl;
    for (int i=0; i<bookedCount; i++){
        cout<<"Name: "<<passengers[i]->name<<endl;
        cout<<"ID: "<<passengers[i]->ID<<endl;
    }
}
int main(){
    Flight f1("A32-507","Karachi","Los Angeles",5);

    Passenger p1("sara",101);
    p1.requestBooking(f1);
    Passenger p2("anam",102);
    p2.requestBooking(f1);
    Passenger p3("zoe",103);
    p3.requestBooking(f1);
    Passenger p4("mashal",104);
    p4.requestBooking(f1);
    Passenger p5("aisha",105);
    p5.requestBooking(f1);
    Passenger p6("ali",106);
    p6.requestBooking(f1);

    p3.requestCancelling(f1);
    p4.requestUpgrading(f1);

    f1.showFlightDetails();
    f1.showPassengers();
    return 0;
}