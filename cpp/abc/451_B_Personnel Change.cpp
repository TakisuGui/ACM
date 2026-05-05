#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    int n,m; cin>>n>>m;
    vector<int> a(n),b(n);
    unordered_map<int,int> mpa,mpb;
    for(int i=0;i<n;i++)
    {
        cin>>a[i]>>b[i];
        mpa[a[i]]++; mpb[b[i]]++;
    }

    for(int i=1;i<=m;i++)
    {
        cout<<mpb[i]-mpa[i]<<endl;
    }

    return 0;
}