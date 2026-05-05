#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

string s;
unordered_map<char,int> tp;
int max_dex=0;

int main()
{
    cin>>s;
    for(int i=0;i<s.size();i++) tp[s[i]]++;
    for(auto i:tp)
    {
        max_dex=max(max_dex,i.second);
    }
    for(int i=0;i<s.size();i++)
    {
        if(tp[s[i]]==max_dex) continue;
        else cout<<s[i];
    }
    

    return 0;
}