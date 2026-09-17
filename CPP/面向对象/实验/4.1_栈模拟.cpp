#include <iostream>
using namespace std;

const int MaxSize = 100; // 栈中能保存的最多元素个数

// 栈的类模板
template<typename T>
class IStack {
public:
    IStack();           // 栈的构造函数
    void Push(T &n);    // 往栈顶增加元素
    void Pop();         // 从非空栈的栈顶删除一个元素
    T GetTop();         // 返回非空栈的栈顶元素
    bool Empty();       // 判断栈是否为空
    int Size();         // 返回栈中元素的个数
    void ClearStack();  // 将栈清空
    ~IStack();          // 栈的析构函数

private:
    T elem[MaxSize];    // 保存栈中各元素的数组
    int Top;            // 保存栈顶的当前位置
};

// 构造函数
template<typename T>
IStack<T>::IStack() {
    Top = -1;  // 空栈时Top为-1
}

// 入栈操作
template<typename T>
void IStack<T>::Push(T &n) {
    if (Top >= MaxSize - 1) {
        cout << "栈已满，无法入栈！" << endl;
        return;
    }
    elem[++Top] = n;
}

// 出栈操作
template<typename T>
void IStack<T>::Pop() {
    if (Empty()) {
        cout << "栈为空，无法出栈！" << endl;
        return;
    }
    Top--;
}

// 获取栈顶元素
template<typename T>
T IStack<T>::GetTop() {
    if (Empty()) {
        cout << "栈为空，无法获取栈顶元素！" << endl;
        return T();  // 返回默认值
    }
    return elem[Top];
}

// 判断栈是否为空
template<typename T>
bool IStack<T>::Empty() {
    return Top == -1;
}

// 返回栈中元素个数
template<typename T>
int IStack<T>::Size() {
    return Top + 1;
}

// 清空栈
template<typename T>
void IStack<T>::ClearStack() {
    Top = -1;
}

// 析构函数
template<typename T>
IStack<T>::~IStack() {
    // 动态资源清理，此处数组是静态的，无需特殊处理
    ClearStack();
}

// 测试主函数
int main() {
    // 测试整数栈
    cout << "=== 整数栈测试 ===" << endl;
    IStack<int> intStack;
    
    cout << "入栈: 10, 20, 30" << endl;
    int a = 10, b = 20, c = 30;
    intStack.Push(a);
    intStack.Push(b);
    intStack.Push(c);
    
    cout << "栈大小: " << intStack.Size() << endl;
    cout << "栈顶元素: " << intStack.GetTop() << endl;
    
    cout << "出栈一次" << endl;
    intStack.Pop();
    cout << "栈顶元素: " << intStack.GetTop() << endl;
    cout << "栈大小: " << intStack.Size() << endl;
    
    // 测试字符栈
    cout << "\n=== 字符栈测试 ===" << endl;
    IStack<char> charStack;
    
    cout << "入栈: A, B, C" << endl;
    char ch1 = 'A', ch2 = 'B', ch3 = 'C';
    charStack.Push(ch1);
    charStack.Push(ch2);
    charStack.Push(ch3);
    
    cout << "栈大小: " << charStack.Size() << endl;
    cout << "栈顶元素: " << charStack.GetTop() << endl;
    
    cout << "清空栈" << endl;
    charStack.ClearStack();
    cout << "栈是否为空: " << (charStack.Empty() ? "是" : "否") << endl;
    
    return 0;
}