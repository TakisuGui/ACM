#include <iostream>
#include <cmath>
using namespace std;

class Point {
public:
    Point() { x = 0; y = 0; }
    Point(double xv, double yv) { x = xv; y = yv; }
    Point(Point& pt) { x = pt.x; y = pt.y; }
    double getx() { return x; }
    double gety() { return y; }
    double Area() { return 0; }
    void Show() { cout << "x=" << x << ' ' << "y=" << y << endl; }
private:
    double x, y;
};

class Rectangle : public Point {
public:
    Rectangle(Point tl, double wd, double ht) : topLeft(tl), width(wd), height(ht) {}
    
    int position(Point &pt) {
        double px = pt.getx(), py = pt.gety();
        double x1 = topLeft.getx(), y1 = topLeft.gety();
        double x2 = x1 + width, y2 = y1 + height;
        
        if (px >= x1 && px <= x2 && py >= y1 && py <= y2) {
            if (px == x1 || px == x2 || py == y1 || py == y2)
                return 0;   // 在边缘
            else
                return 1;   // 在内部
        }
        return -1;          // 在外部
    }
    
    void Show() {
        cout << "矩形：左上角(" << topLeft.getx() << "," << topLeft.gety() 
             << ")，宽=" << width << "，高=" << height << endl;
    }
    
private:
    Point topLeft;
    double width, height;
};

class Circle : public Point {
public:
    Circle(Point c, double r) : center(c), radius(r) {}
    
    int position(Point &pt) {
        double dx = pt.getx() - center.getx();
        double dy = pt.gety() - center.gety();
        double dist2 = dx*dx + dy*dy;
        double r2 = radius * radius;
        
        if (fabs(dist2 - r2) < 1e-9)
            return 0;   // 在边缘
        else if (dist2 < r2)
            return 1;   // 在内部
        else
            return -1;  // 在外部
    }
    
    void Show() {
        cout << "圆：圆心(" << center.getx() << "," << center.gety() 
             << ")，半径=" << radius << endl;
    }
    
private:
    Point center;
    double radius;
};

// 辅助函数：将position的返回值转换为文字描述
void printPosition(int pos) {
    if (pos == 1)
        cout << "在图形内部" << endl;
    else if (pos == 0)
        cout << "在图形边缘上" << endl;
    else
        cout << "在图形外部" << endl;
}

int main() {
    // 测试矩形类
    cout << "========== 测试矩形类 ==========" << endl;
    Point topLeft(2, 5);
    Rectangle rect(topLeft, 8, 4);  // 左上角(2,5)，宽8，高4，右下角(10,9)
    rect.Show();
    
    Point p1(5, 7);      // 矩形内部点
    Point p2(2, 5);      // 矩形左上角顶点（边缘）
    Point p3(10, 9);     // 矩形右下角顶点（边缘）
    Point p4(2, 6);      // 矩形左边上的点（边缘）
    Point p5(11, 7);     // 矩形外部点
    
    cout << "\n点(5,7):";
    printPosition(rect.position(p1));
    cout << "点(2,5):";
    printPosition(rect.position(p2));
    cout << "点(10,9):";
    printPosition(rect.position(p3));
    cout << "点(2,6):";
    printPosition(rect.position(p4));
    cout << "点(11,7):";
    printPosition(rect.position(p5));
    
    // 测试圆类
    cout << "\n========== 测试圆类 ==========" << endl;
    Point center(0, 0);
    Circle circle(center, 5);  // 圆心(0,0)，半径5
    circle.Show();
    
    Point p6(0, 0);      // 圆心（内部）
    Point p7(3, 4);      // 距离圆心5，在圆上（边缘）
    Point p8(3, 3);      // 距离圆心约4.24，内部
    Point p9(5, 5);      // 距离圆心约7.07，外部
    
    cout << "\n点(0,0):";
    printPosition(circle.position(p6));
    cout << "点(3,4):";
    printPosition(circle.position(p7));
    cout << "点(3,3):";
    printPosition(circle.position(p8));
    cout << "点(5,5):";
    printPosition(circle.position(p9));
    
    return 0;
}