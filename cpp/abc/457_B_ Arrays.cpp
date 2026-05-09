#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


int main()
{
    int n; cin>>n;
    vector<vector<int>> a(n);

    for(int i=0;i<n;i++)
    {
        int x; cin>>x;
        a[i].resize(x);
        for(int j=0;j<x;j++) cin>>a[i][j];
    }

    int x,y; cin>>x>>y;
    cout<<a[x-1][y-1]<<endl;

    return 0;
}