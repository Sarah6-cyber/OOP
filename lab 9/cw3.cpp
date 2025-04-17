#include<iostream>
using namespace std;

class Billing;
class Doctor;

class PatientRecord{
    string name, dob, medicalHistory, currentTreatment, billingInfo;
    int ID;
    void setMedicalRecord(string history, string treatment){
        medicalHistory=history;
        currentTreatment=treatment;
    }
    void setBillingInfo(string info){
        billingInfo=info;
    }
    void getMedicalData(){
        cout<<"Name: "<<name<<endl;
        cout<<"ID: "<<ID<<endl;
        cout<<"Date of birth: "<<dob<<endl;
        cout<<"Medical History: "<<medicalHistory<<endl;
        cout<<"Current Treatment: "<<currentTreatment<<endl;
    }
    void getBillingInfo(){
        cout<<"Billing Info: "<<endl<<billingInfo<<endl;
    }
    friend class Doctor;
    friend class Billing;
    public:
    PatientRecord(string n, int id, string d){
        name=n;
        ID=id;
        dob=d;
    }
    void getPublicData(){
        cout<<"Name: "<<name<<endl;
        cout<<"ID: "<<ID<<endl;
        cout<<"Date of birth: "<<dob<<endl;
    }
};

class Doctor{
    public:
    void updateMedicalHistory(PatientRecord &p,string history,string treatment){
        p.setMedicalRecord(history,treatment);
        cout<<endl;
        cout<<"Medical history and treatment updated"<<endl;
        cout<<"---------------------"<<endl;
    }
    void accessMedicalData(PatientRecord &p){
        p.getMedicalData();
    }
};

class Billing{
    public:
    void addBillingDetails(PatientRecord &p, string info){
        p.setBillingInfo(info);
        cout<<endl;
        cout<<"Billing info added"<<endl;
        cout<<"----------------"<<endl;
    }
    void accessBill(PatientRecord &p){
        p.getBillingInfo();
    }
};

int main(){
    PatientRecord p1("sara",101,"06-09-05");
    Doctor d1;
    Billing b1;

    d1.updateMedicalHistory(p1,"Dust Allergy, cancer","anti-allergies");
    d1.accessMedicalData(p1);
    d1.updateMedicalHistory(p1,"Dust Allergy, cancer","anti-allergies, chemotherapy");
    d1.accessMedicalData(p1);

    b1.addBillingDetails(p1,"Doctor's fees: $1500");
    b1.accessBill(p1);

    return 0;
}