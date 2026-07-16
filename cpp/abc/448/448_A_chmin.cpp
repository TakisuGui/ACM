#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int n;
int a[101];
int x;

int main()
{
    cin>>n>>x;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(a[i]<x)
        {
            x=a[i];
            cout<<"1"<<endl;
        }
        else cout<<"0"<<endl;
    }

    return 0;
}