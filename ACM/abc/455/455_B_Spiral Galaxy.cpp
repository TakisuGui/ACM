#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=15;

int a[N][N];

void solve()
{
    int h,w; cin>>h>>w;

    for(int i=1;i<=h;i++)
    {
        string text; cin>>text;
        for(int j=0;j<w;j++) (text[j]=='.' ? a[i][j+1]=1 : a[i][j+1]=0);
    }

    int ans=0;

    for(int h1=1;h1<=h;h1++)
    {
        for(int h2=h1;h2<=h;h2++)
        {
            for(int w1=1;w1<=w;w1++)
            {
                for(int w2=w1;w2<=w;w2++)
                {
                    int pass=true;

                    for(int i=h1;i<=h2;i++)
                    {
                        for(int j=w1;j<=w2;j++)
                        {
                            if(a[i][j]!=a[h1+h2-i][w1+w2-j])
                            {
                                pass=false;
                                break;
                            }
                        }
                        
                        if(!pass) break;
                    }

                    if(pass) ans++;
                }
            }
        }
    }

    cout<<ans<<endl;
}


int main()
{

    ios::sync_with_stdio(false);
    cin.tie(0);

    int t; t=1;
    while(t--)
    {
        solve();
    }

    return 0;
}