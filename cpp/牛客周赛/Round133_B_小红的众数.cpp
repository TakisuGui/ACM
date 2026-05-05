#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

unordered_map<int, int> tp;
int n,x;

int main()
{
    cin>>n>>x;
    while(n--)
    {
        int k; cin>>k;
        tp[k]++;
    }
   
    int max_dex=0;
    for(auto u:tp)
    {
        max_dex=max(max_dex,u.second);
    }
    
    cout<<max_dex-tp[x]<<endl;
    
    return 0;
}