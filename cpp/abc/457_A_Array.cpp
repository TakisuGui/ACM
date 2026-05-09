#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


int main()
{
    int n; cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    int x; cin>>x;
    cout<<a[x-1]<<endl;
    
    return 0;
}