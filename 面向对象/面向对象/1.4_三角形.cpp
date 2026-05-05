#include <iostream>
#include <cmath>
using namespace std;


class myPoint {  
public:

    myPoint(double x0 = 0.0, double y0 = 0.0) : x(x0), y(y0) {}
    
    myPoint(myPoint &np) : x(np.x), y(np.y) {}

    double GetX() { return x; }
    double GetY() { return y; }

    void SetX(double x0) { x = x0; }
    void SetY(double y0) { y = y0; }
    void SetPoint(double x0, double y0) { x = x0; y = y0; }
    void SetPoint(myPoint &np) { x = np.x; y = np.y; }

    double GetLength(myPoint p) {
        return sqrt((x - p.x) * (x - p.x) + (y - p.y) * (y - p.y));
    }

    void Printit() { 
        cout << " (" << x << "," << y << ") ";
    }
    
private:
    double x, y;
};

class Triangle {
private:
    myPoint p1, p2, p3; 
    
public:
    Triangle(myPoint &a, myPoint &b, myPoint &c) : p1(a), p2(b), p3(c) {}
    
    double GetPerimeter() {
        double side1 = p1.GetLength(p2);
        double side2 = p2.GetLength(p3);
        double side3 = p3.GetLength(p1);
        return side1 + side2 + side3;
    }
    
    double GetArea() {
        double side1 = p1.GetLength(p2);
        double side2 = p2.GetLength(p3);
        double side3 = p3.GetLength(p1);
        
        double s = (side1 + side2 + side3) / 2;
        return sqrt(s * (s - side1) * (s - side2) * (s - side3));
    }

    void PrintTriangle() {
        cout << "三角形顶点坐标：" << endl;
        cout << "顶点1: ";
        p1.Printit();
        cout << endl;
        cout << "顶点2: ";
        p2.Printit();
        cout << endl;
        cout << "顶点3: ";
        p3.Printit();
        cout << endl;
        cout << "周长 = " << GetPerimeter() << endl;
        cout << "面积 = " << GetArea() << endl;
    }
};

int main() {

    myPoint a(0, 0);   
    myPoint b(3, 0);   
    myPoint c(0, 4);   
    

    Triangle tri(a, b, c);
    

    tri.PrintTriangle();
    
    return 0;
}