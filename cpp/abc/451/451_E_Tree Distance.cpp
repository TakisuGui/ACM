#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int dist[3005][3005];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin>>n;

    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            cin>>dist[i][j];
            dist[j][i]=dist[i][j];
        }
    }

    ll edge_count=0;

    for(int i=0;i<n;i++)
    {
        for(int j=i+1;i<n;j++)
        {
            bool is_direct=true;
            for(int k=0;k<n;k++)
            {
                if(k==i||k==j) continue;

                if(dist[i][j]>dist[i][k]+dist[k][j])
                {
                    cout<<"No"<<endl;
                    return 0;
                }

                if(dist[i][j]==dist[i][k]+dist[k][j]) is_direct=false;
            }
            if (is_direct) edge_count++;
        }
    }

    if (edge_count == (long long)n - 1) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;

    return 0;
}