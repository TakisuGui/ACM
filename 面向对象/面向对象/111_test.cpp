#include <iostream> 
using namespace std; 
class Base { 
int x; 
public: 
void setX(int a){x=a;} 
int getX(){return x;} 
}; 
class DemoA :virtual public Base {}; 
class DemoB :virtual public Base {}; 
class Derived : public DemoA, public DemoB { 
public: 
int getX(){ return DemoA::getX();} 
}; 
int main(){ 
Derived d; 
d.DemoA::setX(6); 
d.DemoB::setX(25); 
cout<<"x="<<d.getX()<<endl; 
return 0; 
} 





