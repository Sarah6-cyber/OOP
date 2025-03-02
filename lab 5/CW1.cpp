#include <iostream>

using namespace std;

class Engine{
    bool isRunning;
    public:
    Engine(){
        isRunning=false;
        cout<<"engine constructed"<<endl;
    }
    ~Engine(){
        cout<<"engine destructed"<<endl;
    }
    void start(){
        if(!isRunning){
            isRunning=true;
            cout <<"engine started"<<endl;
        }
        else{
            cout<<"Engine is already running"<<endl; 
        }
    }
    void stop() {
        if(isRunning){
            isRunning=false;
            cout<<"Engine stopped"<<endl;
        }
        else {
            cout<<"Engine is stopped already"<<endl;
        }
    }
};

class Car{
    Engine engine; 
    public:
    Car(){
        cout<<"Car constructed"<<endl; 
    }
    ~Car(){
        cout<<"Car destructed"<<endl;  
    }
    void startCar(){
        engine.start();
        cout<<"car started"<<endl;
    }
    void stopCar(){
        engine.stop();
        cout<<"car stopped"<<endl;
    }
};

int main(){
    Car c; 
    c.startCar();
    c.stopCar();
    return 0;
}