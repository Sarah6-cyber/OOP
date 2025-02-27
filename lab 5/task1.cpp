#include<iostream>
#include<chrono>
#include<thread>
using namespace std;

class Blend{
    public:
    void blendJuice(){
        cout<<"selecting fruits....."<<endl;
        std::this_thread::sleep_for(std::chrono::seconds(1));
        cout<<"let's blend the juice.."<<endl;
        for (int i=0; i<5; i++){
            std::this_thread::sleep_for(std::chrono::seconds(1));
            cout<<"blend...."<<endl;
        }
        cout<<"juice blended completely!"<<endl;
    }
};
class Grind{
    public:
    void grindJuice(){
        cout<<"let's grind the juice.."<<endl;
        for (int i=0; i<6; i++){
            cout<<"grinding juice....."<<endl;
            std::this_thread::sleep_for(std::chrono::seconds(1));
        }
        cout<<"juice grinded completely!"<<endl;
    }
};
class JuiceMaker{
    Blend b;
    Grind g;
    public:
    void Juice(){
        cout<<"juice preperation invoked"<<endl;
        b.blendJuice();
        g.grindJuice();
        cout<<"juice made! ENJOY<3 "<<endl;
    }
};

int main(){
    JuiceMaker Juicer;
    Juicer.Juice();
    return 0;
}