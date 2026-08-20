#include<bits/stdc++.h>
using namespace std;

const int N=1e5+10;

int h[N],e[N],ne[N],idx=0;//ys种类，战力值，下一节点，选手i
int mp[N];



//游玩类别和能力值
void genshen(int x,int id,int ability)
{
    idx++;
    e[idx]=ability;
    mp[idx]=id;  // 记录这个节点对应的学生编号

    ne[idx]=h[x];
    h[x]=idx;
}




//输出
void print(int i)
{
    vector<pair<int, int>> players; 

    for(int p=ne[h[i]];p;p=ne[p])
    {
        players.push_back({e[p],mp[p]});
    }

    if(players.empty()) {
        cout << -1 << endl;
        return;
    }

    sort(players.begin(),players.end());


    for(int j = 0; j < players.size(); j++) {
        cout << players[j].second;
        if(j < players.size() - 1) cout << " ";
    }
    cout << endl;
  

}





int main(){

    int n,m,k;//人数 m种ys，能力值上限

    cin>>n>>m>>k;

    for(int i = 1; i <= m; i++) h[i] = 0;

    for(int p=1;p<=n;p++){
        int a,b;cin>>a>>b;
        genshen(a,p,b);
    }


    for(int p=0;p<m;p++){
        print(p+1);
    }
}