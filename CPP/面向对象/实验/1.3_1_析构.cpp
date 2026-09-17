#include<iostream>  
using namespace std; 

class IntArray {
public:
    IntArray(int sz);
    IntArray( int *array, int sz ); 
    IntArray( const IntArray &rhs ); 
    ~IntArray();                     
    void printAll();
private:
    int *ia;
    int size;
};


IntArray::IntArray( int sz ) { 
    size = sz; 
    ia = new int[ size ]; 
    for ( int ix=0; ix < size; ++ix ) 
        ia[ix] = 0;
}


IntArray::IntArray( int *array, int sz ) { 
    size = sz; 
    ia = new int[ size ]; 
    for ( int ix=0; ix < size; ++ix ) 
        ia[ix] = array[ ix ];
}


IntArray::IntArray( const IntArray &rhs ) { 
    size = rhs.size; 
    ia = new int[ size ]; 
    for (int ix = 0; ix < size; ix++ ) 
        ia[ ix ] = rhs.ia[ ix ]; 
}

IntArray::~IntArray() {
    delete[] ia;
}

void IntArray::printAll() {
    for ( int ix=0; ix < size; ++ix ) 
        cout << ia[ix] << "  ";    
    cout << endl;
}

int main() {
    int a[10] = {1,2,3,4,5,6,7,8,9,10};
    IntArray arr1(10), arr2(a,5), arr3(arr2);
    arr1.printAll();
    arr2.printAll();
    arr3.printAll();
    return 0;
}