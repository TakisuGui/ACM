#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void slove()
{
    int x; cin>>x;
    int a[x+1];
    for(int i=1;i<=x;i++) cin>>a[i];
    sort(a+1,a+1+x);

    cout<<a[x]-a[1]+1<<endl;

}

int main()
{
    int t; cin>>t;
    while(t--)
    {
        slove();
    }

    return 0;
}