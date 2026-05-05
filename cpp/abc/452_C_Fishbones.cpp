#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

bool ok[12][12][27];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n; cin>>n;
    vector<int> a(n+1),b(n+1);
    for(int i=1;i<=n;i++) cin>>a[i]>>b[i];
    
    int m; cin>>m;
    vector<string> s(m);
    for(int i=0;i<m;i++)
    {
        cin>>s[i];
        int len=s[i].size();
        for(int pos=0;pos<len;pos++)
        {
            ok[len][pos+1][s[i][pos]-'a']=true;
        }
    }

    for(int j=0;j<m;j++)
    {
        string check=s[j];

        if(check.size()!=n)
        {
            cout<<"No"<<endl;
            continue;
        }

        bool ex=true;
        for(int i=1;i<=n;i++)
        {
            char c=check[i-1];
            if(!ok[a[i]][b[i]][c-'a'])
            {
                ex=false;
                break;
            }
        }

        if(ex) cout<<"Yes"<<"\n";
        else cout<<"No"<<"\n";
    }

    return 0;
}
