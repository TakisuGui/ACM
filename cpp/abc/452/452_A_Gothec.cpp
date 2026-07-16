#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    int m, n; cin>>m>>n;
    if((m==1&&n==7)||(m==3&n==3)||(m==5&&n==5)||(m==7)&&n==7||(m==9&&n==9))
    cout<<"Yes"<<endl;
    else cout<<"No"<<endl;

    return 0;
}