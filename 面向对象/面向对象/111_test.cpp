#include <iostream>
using namespace std;

class MyClass {
public:
    // 普通构造函数
    MyClass(int n) {
        number = n;
        cout << "普通构造函数: " << number << endl;
    }
    
    // 拷贝构造函数
    MyClass(const MyClass &other) {
        number = other.number;
        cout << "拷贝构造函数: " << number << endl;
    }
    
    ~MyClass() {
        cout << "析构函数: " << number << endl;
    }
    
    int getNumber() const { return number; }
    
private:
    int number;
};

MyClass fun(MyClass p) {
    cout << "进入 fun 函数" << endl;
    MyClass temp(p);
    cout << "准备返回 temp" << endl;
    return temp;
}

int main() {
    cout << "--- 开始 ---" << endl;
    MyClass obj1(10), obj2(0);
    
    cout << "\n--- 执行 MyClass obj3(obj1) ---" << endl;
    MyClass obj3(obj1);
    
    cout << "\n--- 执行 obj2 = fun(obj3) ---" << endl;
    obj2 = fun(obj3);
    
    cout << "\n--- 程序结束，准备析构 ---" << endl;
    return 0;
}

