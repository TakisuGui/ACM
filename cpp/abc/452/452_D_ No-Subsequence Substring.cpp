#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int next_p[200005][26];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    string s,t;
    cin>>s>>t;
    int n=s.size(),m=t.size();

    for (int c=0; c<26;c++) next_p[n+1][c]=n+1;
    for (int c=0; c<26;c++) next_p[n+2][c]=n+1;

    for(int i=n;i>=1;i--)
    {
        for(int c=0;c<26;c++)
        {
            next_p[i][c]=next_p[i+1][c];
        }
        next_p[i][s[i-1]-'a']=i;
    }

    ll total=(ll)n*(n+1)/2;
    ll count=0;

    for(int l=1;l<=n;l++)
    {
        int cur=l;
        bool possible=true;

        for(int j=0;j<m;j++)
        {
            if(cur>n)
            {
                possible=false;
                break;
            }

            int target=t[j]-'a';
            cur=next_p[cur][target];

            if(cur>n)
            {
                possible=false;
                break;
            }
            
            if(j<m-1) cur++;
        }
        if (possible) count+=(n-cur+1);
    }
    cout<<total-count<<endl;

    return 0;
}