#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n"

// 学生结构体
struct Student {
    int id;
    string name;
    int score;
};

// 输入数据到文件
void inputData() {
    ofstream outFile("stud.dat", ios::binary);
    if (!outFile) {
        cout << "无法打开文件！" << endl;
        return;
    }
    
    int n;
    cout << "学生人数:";
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        Student stu;
        cout << "第" << i + 1 << "个学生(学号 姓名 成绩):";
        cin >> stu.id >> stu.name >> stu.score;
        outFile.write(reinterpret_cast<char*>(&stu), sizeof(Student));
    }
    
    outFile.close();
    cout << "数据输入完成！" << endl;
}

// 从文件输出所有数据
void outputData() {
    ifstream inFile("stud.dat", ios::binary);
    if (!inFile) {
        cout << "无法打开文件或文件不存在！请先输入数据。" << endl;
        return;
    }
    
    cout << "输出数据" << endl;
    cout << left << setw(10) << "学号" << setw(10) << "姓名" << setw(10) << "成绩" << endl;
    
    Student stu;
    while (inFile.read(reinterpret_cast<char*>(&stu), sizeof(Student))) {
        cout << left << setw(10) << stu.id << setw(10) << stu.name << setw(10) << stu.score << endl;
    }
    
    inFile.close();
}

// 按姓名查找
void searchByName() {
    ifstream inFile("stud.dat", ios::binary);
    if (!inFile) {
        cout << "无法打开文件或文件不存在！请先输入数据。" << endl;
        return;
    }
    
    string searchName;
    cout << "输入姓名:";
    cin >> searchName;
    
    cout << "输出匹配的结果:" << endl;
    cout << left << setw(10) << "学号" << setw(10) << "姓名" << setw(10) << "成绩" << endl;
    
    Student stu;
    bool found = false;
    
    while (inFile.read(reinterpret_cast<char*>(&stu), sizeof(Student))) {
        // 支持模糊匹配（姓名中包含搜索关键字）或精确匹配
        if (stu.name.find(searchName) != string::npos) {
            cout << left << setw(10) << stu.id << setw(10) << stu.name << setw(10) << stu.score << endl;
            found = true;
        }
    }
    
    if (!found) {
        cout << "未找到匹配的学生！" << endl;
    }
    
    inFile.close();
}

int main() {
    int choice;
    
    while (true) {
        cout << "\n选择(1:输入数据 2:输出数据 3:按姓名查找数据 其他退出):";
        cin >> choice;
        
        switch (choice) {
            case 1:
                inputData();
                break;
            case 2:
                outputData();
                break;
            case 3:
                searchByName();
                break;
            default:
                cout << "程序退出！" << endl;
                return 0;
        }
    }
    
    return 0;
}