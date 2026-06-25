#include <iostream>
#include <cmath>
using namespace std;

class Rational {
private:
    int numerator;   // 分子
    int denominator; // 分母
    
    // 求最大公约数，用于约分
    int gcd(int a, int b) {
        a = abs(a);
        b = abs(b);
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }
    
    // 约分
    void reduce() {
        if (denominator == 0) return;
        int g = gcd(numerator, denominator);
        numerator /= g;
        denominator /= g;
        // 保证分母为正
        if (denominator < 0) {
            numerator = -numerator;
            denominator = -denominator;
        }
    }
    
public:
    Rational(int num = 0, int den = 1) : numerator(num), denominator(den) {
        if (denominator == 0) denominator = 1;
        reduce();
    }
    
    // 重载+运算符
    Rational operator+(const Rational& other) const {
        int new_num = numerator * other.denominator + other.numerator * denominator;
        int new_den = denominator * other.denominator;
        return Rational(new_num, new_den);
    }
    
    // 重载<<运算符（友元函数）
    friend ostream& operator<<(ostream& os, const Rational& r);
};

// 重载输出运算符
ostream& operator<<(ostream& os, const Rational& r) {
    if (r.denominator == 1)
        os << r.numerator;
    else
        os << r.numerator << "/" << r.denominator;
    return os;
}

int main() {
    Rational x(1, 3), y(1, 6), z;
    z = x + y;
    cout << x << " + " << y << " = " << z << endl;
    return 0;
}