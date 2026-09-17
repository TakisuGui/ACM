#include<bits/stdc++.h>
using namespace std;

const int N=100;

double a[N],b[N];


int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];

    }

    for(int i=0;i<n;i++)
    {
        cin>>b[i];

    }

    double ans=0;

    for(int i=0;i<n;i++)
    {
        ans=ans+a[i]*b[i];
    }

    printf("%lf",ans);



    return 0;
}