#include <iostream>
#include <cmath>
using namespace std;

// 基类：几何图形
class Geometric_shape {
public:
    virtual double perimeter() = 0;  // 周长
    virtual double area() = 0;       // 面积
    virtual double volume() = 0;     // 体积（平面图形返回0）
    virtual void Show() = 0;         // 显示图形类型
    virtual ~Geometric_shape() {}    // 虚析构函数
};

// 圆形
class Circle : public Geometric_shape {
private:
    double radius;
public:
    Circle(double r) : radius(r) {}
    double perimeter() { return 2 * M_PI * radius; }
    double area() { return M_PI * radius * radius; }
    double volume() { return 0; }
    void Show() { cout << "圆形"; }
};

// 矩形
class Rectangle : public Geometric_shape {
private:
    double length, width;
public:
    Rectangle(double l, double w) : length(l), width(w) {}
    double perimeter() { return 2 * (length + width); }
    double area() { return length * width; }
    double volume() { return 0; }
    void Show() { cout << "矩形"; }
};

// 三角形
class Triangle : public Geometric_shape {
private:
    double a, b, c;
public:
    Triangle(double x, double y, double z) : a(x), b(y), c(z) {}
    double perimeter() { return a + b + c; }
    double area() {
        double s = (a + b + c) / 2;
        return sqrt(s * (s - a) * (s - b) * (s - c));
    }
    double volume() { return 0; }
    void Show() { cout << "三角形"; }
};

// 长方体
class Box : public Geometric_shape {
private:
    double length, width, height;
public:
    Box(double l, double w, double h) : length(l), width(w), height(h) {}
    double perimeter() { return 2 * (length + width); }  // 底面周长
    double area() { return length * width; }             // 底面积
    double volume() { return length * width * height; }
    void Show() { cout << "长方体"; }
};

// 圆柱
class Cylinder : public Geometric_shape {
private:
    double radius, height;
public:
    Cylinder(double r, double h) : radius(r), height(h) {}
    double perimeter() { return 2 * M_PI * radius; }     // 底面周长
    double area() { return M_PI * radius * radius; }     // 底面积
    double volume() { return M_PI * radius * radius * height; }
    void Show() { cout << "圆柱"; }
};

// 圆锥
class Cone : public Geometric_shape {
private:
    double radius, height;
public:
    Cone(double r, double h) : radius(r), height(h) {}
    double perimeter() { return 2 * M_PI * radius; }     // 底面周长
    double area() { return M_PI * radius * radius; }     // 底面积
    double volume() { return (1.0 / 3.0) * M_PI * radius * radius * height; }
    void Show() { cout << "圆锥"; }
};

// 三棱柱
class T_prism : public Geometric_shape {
private:
    double a, b, c;   // 底面三角形三边
    double height;    // 棱柱高
public:
    T_prism(double x, double y, double z, double h) : a(x), b(y), c(z), height(h) {}
    double perimeter() { return a + b + c; }             // 底面周长
    double area() {
        double s = (a + b + c) / 2;
        return sqrt(s * (s - a) * (s - b) * (s - c));    // 底面积
    }
    double volume() { return area() * height; }
    void Show() { cout << "三棱柱"; }
};

// 三棱锥
class T_pyramid : public Geometric_shape {
private:
    double a, b, c;   // 底面三角形三边
    double height;    // 棱锥高
public:
    T_pyramid(double x, double y, double z, double h) : a(x), b(y), c(z), height(h) {}
    double perimeter() { return a + b + c; }             // 底面周长
    double area() {
        double s = (a + b + c) / 2;
        return sqrt(s * (s - a) * (s - b) * (s - c));    // 底面积
    }
    double volume() { return (1.0 / 3.0) * area() * height; }
    void Show() { cout << "三棱锥"; }
};

int main() {
    Geometric_shape* gs[] = {
        new Circle(10),
        new Rectangle(6, 8),
        new Triangle(3, 4, 5),
        new Box(6, 8, 3),
        new Cylinder(10, 3),
        new Cone(10, 3),
        new T_pyramid(3, 4, 5, 3),
        new T_prism(3, 4, 5, 3)
    };
    
    for (int i = 0; i < 8; i++) {
        gs[i]->Show();
        cout << endl;
    }
    
    cout << "平面图形：" << endl;
    for (int i = 0; i < 3; i++) {
        cout << "图形周长：" << gs[i]->perimeter() << '\t';
        cout << "图形面积：" << gs[i]->area() << '\t';
        cout << "图形体积：" << gs[i]->volume() << endl;
    }
    
    cout << "立体图形：" << endl;
    for (int i = 3; i < 8; i++) {
        cout << "图形底周长：" << gs[i]->perimeter() << '\t';
        cout << "图形底面积：" << gs[i]->area() << '\t';
        cout << "图形体积：" << gs[i]->volume() << endl;
    }
    
    // 释放内存
    for (int i = 0; i < 8; i++) {
        delete gs[i];
    }
    
    return 0;
}