#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n"
#define int ll
const int N=2e5+10;
const int MOD=1e7+7;


//  Z[i] S从 i 出发 和 S 有多长的的共同前缀
vector<int> get_Z(string s,int n)
{
    vector<int> Z(n,0); Z[0]=n;

    for(int i=1,c=1,r=1,len=0;i<n;i++)
    {
        len=0;
        if(r>i) len=min(Z[i-c],r-i);
        while(i+len<n&&s[i+len]==s[len]) len++;

        if(r<len+i)
        {
            r=i+len;
            c=i;
        }
        Z[i]=len;
    }
    return Z;
}

// E[i] A从i出发 和 B 从0出发 有多长的的共同前缀
vector<int> get_E(vector<int>& Z,string s1,string s2,int n1,int n2)
{
    vector<int> E(n1,0);
    
    for(int i=0,c=0,r=0,len=0;i<n1;i++)
    {
        len=0;
        if(r>i) len=min(Z[i-c],r-i);
        while(i+len<n1&&len<n2&&s1[i+len]==s2[len]) len++;

        if(r<len+i)
        {
            r=len+i;
            c=i;
        }
        E[i]=len;
    }
    return E;
}

int eor(vector<int>& Z,int n)
{
    int ans=0;
    for(int i=0;i<n;i++) ans^=(ll)(i+1)*(Z[i]+1);
    return ans;
}

void solve()
{
    string s1,s2; cin>>s1>>s2;
    int n1=s1.size(),n2=s2.size();

    vector<int> Z=get_Z(s2,n2);
    vector<int> E=get_E(Z,s1,s2,n1,n2);

    int ans1=eor(Z,n2);
    int ans2=eor(E,n1);

    cout<<ans1<<endl<<ans2<<endl;
}


signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll t; t=1;
    while(t--)
    {
        solve();
    }

    return 0;
}