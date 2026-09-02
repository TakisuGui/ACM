#include<bits/stdc++.h>
#include <unordered_map>
#include <variant>
#include <vector>
using namespace std;
typedef long long ll;

unordered_map<string,int> mp;
unordered_map<string,int> visited;


int main()
{
    int n; cin>>n; int ans=0;
    while(n--)
    {
        string word; cin>>word; 
        mp[word]++;
        if(mp[word]>ans&&visited[word]==0) 
        {
            ans++;
            visited[word]=1;
        }
    }

    cout<<ans<<endl;

    return 0;
}