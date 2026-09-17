#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n"

void solve()
{
    int n; cin>>n;
    string s; cin>>s;

    int balance=0;
    for(char c:s)
    {
        if(c=='(') balance++;
        else balance--;
    }

    if(balance==0) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}



int main()
{
    int t; cin>>t;
    while(t--)
    {
        solve();
    }

    return 0;
}