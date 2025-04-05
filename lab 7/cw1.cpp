#include<iostream>
using namespace std;

class Fraction{
    int denominator;
    int numerator;
    public:
    Fraction(int d, int n){
        if (d<0){
            d=-d;
            n=-n;
        }
        if (d==0){
            cout<<"Invalid denominator value"<<endl;
            return;
        }
        int gcd=GCD(d,n);
        denominator=d;
        numerator=n;
        numerator/=gcd;
        denominator/=gcd;
    }
    int GCD(int x, int y){
        while (y!=0){
            int temp=y;
            y=x%y;
            x=temp;
        }
        return x;
    }
    Fraction operator+(const Fraction &f){
        int num=f.numerator*denominator+f.denominator*numerator;
        int den=f.denominator*denominator;
        Fraction fract(num,den);
        return fract;
    }
    Fraction operator-(const Fraction &f){
        int num=f.numerator*denominator-f.denominator*numerator;
        int den=f.denominator*denominator;
        Fraction fract(num,den);
        return fract;
    }
    Fraction operator*(const Fraction &f){
        int num=f.numerator*numerator;
        int den=f.denominator*denominator;
        Fraction fract(num,den);
        return fract;
    }
    Fraction operator/(const Fraction &f){
        int den=f.numerator*denominator;
        int num=f.denominator*numerator;
        Fraction fract(num,den);
        return fract;
    }
    bool operator==(const Fraction &f){
        return numerator==f.numerator && denominator==f.denominator;
    }
    bool operator!=(const Fraction &f){
        return numerator!=f.numerator || denominator!=f.denominator; 
    }
    bool operator>(const Fraction &f){
        return f.denominator*numerator > f.numerator<denominator;
    }
    bool operator<(const Fraction &f){
        return f.denominator*numerator < f.numerator<denominator;
    }
    friend ostream& operator<<(ostream& os, const Fraction& f){
        os<<f.numerator<<"/"<<f.denominator;
        return os;
    }
    friend istream& operator>>(istream& is, Fraction& f){
        cout<<"Enter numerator: "<<endl;
        is>>f.numerator;
        cout<<"Enter denominator: "<<endl;
        is>>f.denominator;
        return is;
    }
};

int main() {
    Fraction f1(4, 12);  
    Fraction f2(3, 6);
    Fraction sum=f1+f2;
    Fraction diff=f1-f2;
    Fraction product=f1*f2;
    Fraction quotient=f1/f2;
    cout<<"Sum: " << sum << endl;
    cout<<"Difference: " << diff << endl;
    cout<<"Product: " << product << endl;
    cout<<"Quotient: " << quotient << endl;
    cout<<"Are the two fractions equal?"<<(f1==f2?"Yes":"No")<<endl;
    cout<<"Are the two fractions not equal?"<<(f1!=f2 ? "Yes":"No")<<endl;
    cout<<"Is fraction 1 greater than fraction 2?" << (f1>f2 ? "Yes":"No")<<endl;
    cout<<"Is fraction 1 smaller than fraction 2?"<<(f1<f2 ? "Yes":"No")<<endl;
    return 0;
}


