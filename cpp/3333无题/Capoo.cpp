#include<bits/stdc++.h>
using namespace std;

int m, n;

vector<string> sentences;
vector<string> abbrs;
vector<string> result;

string s;
string query;

//读取句子
void read(){
    cin>>s;
    sentences.push_back(s);
}

//生成暗语
void tran(){
    string abbr="";
    for(char c:s)
    {
        if(c>='A'&&c<='Z'){
            abbr=abbr+c;
        }
    }

    abbrs.push_back(abbr);
}

//处理查询
void find(){

    cin>>query;


     result.clear();
     
    // 查找匹配的暗语
    for(int j = 0; j < m; j++) {
            if(abbrs[j] == query) {
                result.push_back(sentences[j]);
            }
        }

}


//输出
void print(){

    cout<<result.size()<<endl;
    for(string& s : result) {
            cout << s << endl;
        }

}

int main(){

    cin >> m >> n;

    for(int i = 0; i < m; i++)
    {
        read();
        tran();   
    }

    for(int i = 0; i < n; i++)
    {
        find();
        print();
    }


    return 0;
}