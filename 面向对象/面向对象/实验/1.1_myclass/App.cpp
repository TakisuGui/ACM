#include "MyClass.h"
#include<iostream>
using namespace std;

int main() 
{
    MyClass obj1;
    MyClass obj2(5, 8);   
     
    obj1.Print();  
    obj2.Print();   
    
    return 0;
}