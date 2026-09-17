#include<iostream>
using namespace std;

class Rectangle
{
private:
    double length;
    double width;
public:
    Rectangle(double l, double w)
    {
        length = l;
        width = w;
    }
    double area()
    {
        return length * width;
    }
    double perimeter()
    {
        return 2 * (length + width);
    }
    void display()
    {
        cout << "长 = " << length << ", 宽 = " << width << endl;
        cout << "面积 = " << area() << endl;
        cout << "周长 = " << perimeter() << endl;
    }
};

int main()
{
    // 实例化两个矩形对象
    Rectangle rect1(20, 50);
    Rectangle rect2(3.6, 4.5);
    cout << "矩形1:" << endl;
    rect1.display();
    cout << "\n矩形2:" << endl;
    rect2.display();
    
    return 0;
}




