#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n"

int main()
{
    int n; cin>>n;
    string s; cin>>s;
    int ans=0;
    int dex=0;

    if(s[0]=='a'||s[0]=='h') dex=1;

    for(int i=1;i<n;i++)
    {
        if(s[i-1]=='a'&&s[i]=='h') dex++;
        else if(s[i-1]=='h'&&s[i]=='a') dex++;
        else if(s[i-1]!='h'&&s[i]=='a')
        {
            ans=max(ans,dex);
            dex=1;
        }
        else if(s[i-1]!='a'&&s[i]=='h')
        {
            ans=max(ans,dex);
            dex=1;
        }
        else
        {
            ans=max(ans,dex);
            dex=0;
        }
    }

    ans=max(ans,dex);

    cout<<ans<<endl;

    return 0;
}