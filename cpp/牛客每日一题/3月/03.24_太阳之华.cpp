#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int dx[4]={0,0,-1,1};
int dy[4]={1,-1,0,0};

void solve()
{
    int n,m; cin>>n>>m;
    vector<string> line(n);
    unordered_map<char,int> mp;

    for(int i=0;i<n;i++)
    {
        cin>>line[i];
        for(char c:line[i]) mp[c]++;
    }
    
    int total=n*m;
    if(mp['#']==total)
    {
        cout<<"Red"<<endl;
        return;
    }
    else if(mp['.']==total)
    {
        cout<<"Blue"<<endl;
        return;
    }

    vector<vector<bool>> vis(n,vector<bool>(m,false));

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(line[i][j]=='#'&&!vis[i][j])
            {
                set<pair<int,int>> pass;
                queue<pair<int,int>> q;

                q.push({i,j}); vis[i][j]=true; 
                while(!q.empty())
                {
                    auto top=q.front(); q.pop(); 

                    for(int k=0;k<4;k++)
                    {
                        int nx=top.first+dx[k]; int ny=top.second+dy[k];
                        if(nx<0||nx>=n||ny<0||ny>=m) continue;
                        if(vis[nx][ny]) continue;

                        if(line[nx][ny]=='#')
                        {
                            q.push({nx,ny});
                            vis[nx][ny]=true;
                        }
                        else pass.insert({nx,ny});
                    }
                }

                if(mp['#']+pass.size()==total)
                {
                    cout<<"Red"<<endl;
                    return;
                }

            }
            
        }
    }

    cout<<"Draw"<<endl;
    return;
}


int main()
{
    int t; cin>>t;
    while(t--)
    {
        solve();
    }

    return 0;
}