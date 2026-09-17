#include <bits/stdc++.h>
using namespace std;

const int primes[]={2,3,5,7,11,13,17,19,23,29};
const int P=10;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T; cin>>T;
    while (T--)
    {
        int N,M,Q; cin>>N>>M>>Q;
        vector<vector<int>>low(P,vector<int>(N + 1, 0));
        for(int i=0; i<M;i++)
        {
            int x,y,g; cin>>x>>y>>g;
            for(int j=0;j<P;j++)
            {
                int p=primes[j]; int e=0; int tmp=g;
                while(tmp%p==0)
                {
                    e++;
                    tmp/=p;
                }
                if(e){
                    low[j][x]=max(low[j][x],e);
                    low[j][y]=max(low[j][y],e);
                }
            }
        }
        while(Q--)
        {
            int x,y; cin>>x>>y;
            int ans=1;
            for (int j=0;j<P;j++)
            {
                int e=min(low[j][x],low[j][y]);
                int p=primes[j];
                for (int k=0; k<e;k++) ans*=p;
            }
            cout<<ans<<"\n";
        }
    }
    return 0;
}