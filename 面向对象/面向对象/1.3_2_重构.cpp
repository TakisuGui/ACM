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
    void init(const int *src, int sz);
};


void IntArray::init(const int *src, int sz) {
    size = sz;
    ia = new int[size];
    for (int i = 0; i < size; ++i) {
        ia[i] = src[i];
    }
}

IntArray::IntArray(int sz) {
    int *temp = new int[sz]();
    init(temp, sz);
    delete[] temp;
}

IntArray::IntArray(int *array, int sz) {
    init(array, sz);
}

IntArray::IntArray(const IntArray &rhs) {
    init(rhs.ia, rhs.size);
}


IntArray::~IntArray() {
    delete[] ia;
}

void IntArray::printAll() {
    for (int ix = 0; ix < size; ++ix) 
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