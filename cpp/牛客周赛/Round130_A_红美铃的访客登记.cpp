#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

string a;

int main()
{
    cin>>a;
    int n=a.size();
    
    for(int i=0;i<n;i++)
    {
        if(i==0&&a[i]=='0') continue;
        else if(i>0&&a[i]=='0'&&a[i-1]=='0') continue;

        cout<<a[i];
    }
    
    return 0;
}