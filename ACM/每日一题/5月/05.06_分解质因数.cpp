#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n"
#define int ll
const int N=1e6+10;

vector<int> a;
bool is_not_prime[N];
int nums;
vector<int> ans;

void ini()
{
    is_not_prime[2]=false; nums=1;

    for(int i=2;i<N;i++)
    {
        if(!is_not_prime[i])
        {
            for(int j=i*i;j<N;j+=i) is_not_prime[j]=true;

            a.push_back(i);
            nums++;
        }
    }
}

void solve()
{
    int n; cin>>n;
    unordered_map<int,int> mp;
    int i=0;

    while(n>=2&&i<nums&&a[i]*a[i]<=n)
    {
        while(n%a[i]==0)
        {
            n/=a[i];
            mp[a[i]]++;
        }
        i++;
    }

    if(n>1) ans.push_back(n);
    for(auto [key,value] : mp)
    {
        for(int k=0;k<value;k++) ans.push_back(key);
    }

    sort(ans.begin(),ans.end());

    for(auto t:ans) cout<<t<<" ";
}


signed main()
{

    ios::sync_with_stdio(false);
    cin.tie(0);

    ini();

    int t; t=1;
    while(t--)
    {
        solve();
    }

    return 0;
}