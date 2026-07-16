#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


void solve()
{
    string s; cin>>s;
    int l=0,r=s.size()-1;

    while(l<=r)
    {
        bool f1 =(s[l]=='m') || (l+1<=r && s[l]=='n' && s[l+1]=='n');
        bool f2 =(s[r]=='m') || (l<=r-1 && s[r]=='n' && s[r-1]=='n');

        if(f1&&f2)
        {
            l+=(s[l]=='m' ? 1:2);
            r-=(s[r]=='n' ? 2:1);
        }
        else if(s[l]=='n'&&s[r]=='n')
        {
            l++,r--;
        }
        else
        {
            cout<<"NO"<<endl;
            return;
        }
    }

    cout<<"YES"<<endl;
}


int main()
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