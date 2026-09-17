#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n"
const int N=2e5+10;

int get_mex(int L,int R,int len,vector<int> &a,int n)
{
    if (a[L] != a[R]) return 0;

    while (L >0 && R < len - 1 && a[L - 1] == a[R + 1])  L--, R++;

    static bool present[200005]; 
    for(int i = L; i <= R; i++) if(a[i] < n) present[a[i]] = true;
    

    int res = 0;
    while(res < n && present[res]) res++;

    for(int i = L; i <= R; i++) if(a[i] < n) present[a[i]] = false;
    
    
    return res;
}

void solve()
{
    int n; cin>>n;
    int len=2*n;
    vector<int> a(len);

    int p1=-1,p2=-1;
    for(int i=0;i<len;i++)
    {
        cin>>a[i];
        if(a[i]==0)
        {
            if(p1==-1) p1=i;
            else p2=i;
        }
    }

    int ans=0;

    ans=max(ans,get_mex(p1,p1,len,a,n));
    ans=max(ans,get_mex(p2,p2,len,a,n));
    ans=max(ans,get_mex((p1+p2)/2,(p1+p2+1)/2,len,a,n));

    cout<<ans<<endl;
}



int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t; cin>>t;
    while(t--)
    {
        solve();
    }

    return 0;
}