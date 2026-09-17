#include<bits/stdc++.h>
using namespace std;

const int N=1e5+10;

int n;
vector<int> a(N);

int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];

    sort(a.begin()+1,a.begin()+n+1);

    int p=(1+n)/2;

    int length=0;

    for(int i=1;i<=n;i++)
    {
        length+=abs(a[i]-a[p]);
    }

    cout<<length<<endl;

    return 0;
}