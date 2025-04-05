#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

class BigInteger{
    private:
    vector<int> digits;
    bool isNegative;
    void removeLeadingZeros() {
        while (digits.size() > 1 && digits.back() == 0)
            digits.pop_back();
        if (digits.size() == 1 && digits[0] == 0)
            isNegative = false;
    }
    static bool absLess(const BigInteger& a, const BigInteger& b) {
        if (a.digits.size() != b.digits.size())
            return a.digits.size() < b.digits.size();
        for (int i = a.digits.size() - 1; i >= 0; --i) {
            if (a.digits[i] != b.digits[i])
                return a.digits[i] < b.digits[i];
        }
        return false;
    }
    static BigInteger absAdd(const BigInteger& a, const BigInteger& b) {
        BigInteger result;
        int carry = 0, sum = 0;
        size_t maxSize = max(a.digits.size(), b.digits.size());

        for (size_t i = 0; i < maxSize || carry; ++i) {
            sum = carry;
            if (i < a.digits.size()) sum += a.digits[i];
            if (i < b.digits.size()) sum += b.digits[i];
            result.digits.push_back(sum % 10);
            carry = sum / 10;
        }

        result.removeLeadingZeros();
        return result;
    }
    static BigInteger absSubtract(const BigInteger& a, const BigInteger& b) {
        BigInteger result;
        int borrow = 0, sub;

        for (size_t i = 0; i < a.digits.size(); ++i) {
            sub = a.digits[i] - borrow - (i < b.digits.size() ? b.digits[i] : 0);
            if (sub < 0) {
                sub += 10;
                borrow = 1;
            } else borrow = 0;
            result.digits.push_back(sub);
        }

        result.removeLeadingZeros();
        return result;
    }
    public:
    BigInteger() : isNegative(false) {
        digits.push_back(0);
    }
    BigInteger(string number) {
        isNegative = (number[0] == '-');
        int start = isNegative ? 1 : 0;

        for (int i = number.size() - 1; i >= start; --i)
            digits.push_back(number[i] - '0');

        removeLeadingZeros();
    }
    friend istream& operator>>(istream& in, BigInteger& num) {
        string input;
        in >> input;
        num = BigInteger(input);
        return in;
    }
    friend ostream& operator<<(ostream& out, const BigInteger& num) {
        if (num.isNegative) out << "-";
        for (int i = num.digits.size() - 1; i >= 0; --i)
            out << num.digits[i];
        return out;
    }
    BigInteger operator+(const BigInteger& other) const {
        BigInteger result;

        if (isNegative == other.isNegative) {
            result = absAdd(*this, other);
            result.isNegative = isNegative;
        } else {
            if (absLess(*this, other)) {
                result = absSubtract(other, *this);
                result.isNegative = other.isNegative;
            } else {
                result = absSubtract(*this, other);
                result.isNegative = isNegative;
            }
        }

        return result;
    }
    BigInteger operator-(const BigInteger& other) const {
        BigInteger negOther = other;
        negOther.isNegative = !negOther.isNegative;
        return *this + negOther;
    }
    bool operator==(const BigInteger& other) const {
        return isNegative == other.isNegative && digits == other.digits;
    }
    bool operator!=(const BigInteger& other) const {
        return !(*this == other);
    }
    bool operator<(const BigInteger& other) const {
        if (isNegative != other.isNegative)
            return isNegative;

        bool result = absLess(*this, other);
        return isNegative ? !result && *this != other : result;
    }
    bool operator>(const BigInteger& other) const {
        return other < *this;
    }
    bool operator<=(const BigInteger& other) const {
        return !(other < *this);
    }
    bool operator>=(const BigInteger& other) const {
        return !(*this < other);
    }
};

int main() {
    BigInteger a, b;
    cout<<"Enter first big integer: ";
    cin>>a;
    cout<<"Enter second big integer: ";
    cin>>b;

    cout<<"a+b= "<<a+b<<endl;
    cout<<"a-b= "<<a-b<<endl;
    cout<<"Comparison (a < b): "<<(a<b)<<endl;
}
