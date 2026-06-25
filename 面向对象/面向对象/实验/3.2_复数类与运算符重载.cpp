#include <iostream>
using namespace std;

class Complex {
private:
    double real;
    double imag;
    
public:
    Complex(double r = 0, double i = 0) : real(r), imag(i) {}
    
    // 重载+运算符作为成员函数
    Complex operator+(const Complex& other) const {
        return Complex(real + other.real, imag + other.imag);
    }
    
    // 重载+运算符作为友元函数，支持 实数 + 复数
    friend Complex operator+(double d, const Complex& c);
    
    void display() const {
        cout << "(" << real << "," << imag << ")" << endl;
    }
    
    double getReal() const { return real; }
    double getImag() const { return imag; }
};

// 友元函数实现：实数 + 复数
Complex operator+(double d, const Complex& c) {
    return Complex(d + c.real, c.imag);
}

int main() {
    Complex a(2, 5), b(7, 8), c(0, 0);
    
    c = a + b;
    cout << "a + b = ";
    c.display();
    
    c = 4.1 + a;
    cout << "4.1 + a = ";
    c.display();
    
    return 0;
}