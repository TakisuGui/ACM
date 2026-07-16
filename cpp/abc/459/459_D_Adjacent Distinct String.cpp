#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n"
#define int ll
const int N=1e6+10;

void solve()
{
    priority_queue<pair<int,char>,vector<pair<int,char>>,less<pair<int,char>>> heap_big;
    vector<int> cnt(26,0);

    string s; cin>>s;
    for(char c: s) cnt[c-'a']++;

    for(int i=0;i<26;i++) if(cnt[i]>0) heap_big.push({cnt[i], (char)('a'+i) });

    char pass='0';

    if(!heap_big.empty())
    {
        auto [index,ch]=heap_big.top();
        if(index>(s.size()+1)/2)
        {
            cout<<"No"<<endl;
            return;
        }
    }

    cout<<"Yes"<<endl;

    while(!heap_big.empty())
    {
        auto [index,ch]=heap_big.top(); heap_big.pop();

        if(ch!=pass)
        {
            pass=ch;
            cout<<pass;
            index--;
            if(index>0) heap_big.push({index,ch});
        }
        else
        {
            auto[index_else,ch_else]=heap_big.top(); heap_big.pop();
            cout<<ch_else;
            pass=ch_else;
            index_else--;
            if(index_else>0) heap_big.push({index_else,ch_else});
            heap_big.push({index,ch});
        }
    }

    cout<<endl;
}


signed main()
{

    ios::sync_with_stdio(false);
    cin.tie(0);

    int t; cin>>t;
    while(t--)
    {
        solve();
    }

    return 0;
}