#include<iostream> 
using namespace std;
class Base
{
    int x;
    
public:
    Base()
    {
        cout<<"Base构造函数的调用"<<endl;
    }


    
};

int main()
{
    Base b[2];
    return 0;
}
