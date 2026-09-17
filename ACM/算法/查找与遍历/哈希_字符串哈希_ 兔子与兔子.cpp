#include<bits/stdc++.h>
using namespace std;

typedef unsigned long long ULL;
const int N=1e6+10,p=13331;

char s[N];
int m;
ULL f[N];
ULL P[N];

void get_hash()
{
    f[0]=tolower(s[0])-'a'+1;
    P[0]=1;
    for(int i=1;s[i]!='\0';i++)
    {
        f[i]=f[i-1]*p+tolower(s[i])-'a'+1;
        P[i]=P[i-1]*p;
    }
}


int main()
{
    cin>>s;
    get_hash();

    cin>>m;
    
    for(int i=1;i<=m;i++)
    {
        int l1,r1,l2,r2;
        ULL ans1,ans2;
        cin>>l1>>r1>>l2>>r2;
        l1--;r1--;l2--;r2--;

        if(l1==0) ans1=f[r1];
        else ans1=f[r1]-f[l1-1]*P[r1-l1+1];

        if(l2==0)  ans2=f[r2];
        else  ans2=f[r2]-f[l2-1]*P[r2-l2+1];

        if(ans1==ans2) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }

    return 0;
}