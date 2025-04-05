#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

class Polynomial;

class PolynomialUtils {
public:
    int evaluate(const Polynomial &p, int x);
    Polynomial derivative(const Polynomial &p);
};

class Polynomial {
    private:
    vector<int> coefficients;
    void trim() {
        while (!coefficients.empty() && coefficients.back() == 0) {
            coefficients.pop_back();
        }
    }

    public:
    Polynomial() {}
    Polynomial(const vector<int>& coeffs) {
        coefficients = coeffs;
        trim();
    }
    Polynomial operator+(const Polynomial &rhs) const {
        vector<int> result(max(coefficients.size(), rhs.coefficients.size()), 0);
        for (size_t i = 0; i < coefficients.size(); i++)
            result[i] += coefficients[i];
        for (size_t i = 0; i < rhs.coefficients.size(); i++)
            result[i] += rhs.coefficients[i];
        return Polynomial(result);
    }
    Polynomial operator-(const Polynomial &rhs) const {
        vector<int> result(max(coefficients.size(), rhs.coefficients.size()), 0);
        for (size_t i = 0; i < coefficients.size(); i++)
            result[i] += coefficients[i];
        for (size_t i = 0; i < rhs.coefficients.size(); i++)
            result[i] -= rhs.coefficients[i];
        return Polynomial(result);
    }
    Polynomial operator*(const Polynomial &rhs) const {
        vector<int> result(coefficients.size() + rhs.coefficients.size() - 1, 0);
        for (size_t i = 0; i < coefficients.size(); i++)
            for (size_t j = 0; j < rhs.coefficients.size(); j++)
                result[i + j] += coefficients[i] * rhs.coefficients[j];
        return Polynomial(result);
    }
    friend ostream& operator<<(ostream &out, const Polynomial &p) {
        if (p.coefficients.empty()) {
            out << "0";
            return out;
        }

        bool first = true;
        for (int i = p.coefficients.size() - 1; i >= 0; i--) {
            int coef = p.coefficients[i];
            if (coef == 0) continue;

            if (!first) {
                out << (coef > 0 ? " + " : " - ");
            } else if (coef < 0) {
                out << "-";
            }

            if (abs(coef) != 1 || i == 0)
                out << (first ? coef : abs(coef));

            if (i >= 1)
                out << "x";
            if (i > 1)
                out << "^" << i;

            first = false;
        }

        return out;
    }
    friend class PolynomialUtils;
};

int PolynomialUtils::evaluate(const Polynomial &p, int x) {
    int result = 0;
    for (size_t i = 0; i < p.coefficients.size(); i++) {
        result += p.coefficients[i] * pow(x, i);
    }
    return result;
}

Polynomial PolynomialUtils::derivative(const Polynomial &p) {
    if (p.coefficients.size() <= 1)
        return Polynomial({0});

    vector<int> result(p.coefficients.size() - 1);
    for (size_t i = 1; i < p.coefficients.size(); i++) {
        result[i - 1] = p.coefficients[i] * i;
    }
    return Polynomial(result);
}

int main() {
    vector<int>coeffs1={3, 2, -1};     
    vector<int>coeffs2={-2, 2, 3}; 

    Polynomial p1(coeffs1);
    Polynomial p2(coeffs2);

    Polynomial sum=p1+p2;
    Polynomial diff=p1-p2;
    Polynomial prod=p1*p2;

    PolynomialUtils utils;

    cout<<"P1: "<<p1<<endl;
    cout<<"P2: "<<p2<<endl;
    cout<<"Sum: "<<sum<<endl;
    cout<<"Difference: "<<diff<<endl;
    cout<<"Product: "<<prod<<endl;
    cout<<"P1 evaluated at x=2: "<<utils.evaluate(p1, 2)<<endl;
    cout<<"Derivative of P1: "<<utils.derivative(p1)<<endl;

    return 0;
}
