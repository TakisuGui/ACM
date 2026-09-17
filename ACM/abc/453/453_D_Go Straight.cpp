#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N=1e3+10;
const int dx[4]={-1,1,0,0};
const int dy[4]={0,0,-1,1};
char dir_char[] = {'U','D','L','R'};
struct State{int r,c,d;};
pair<int,int> pre[N][N][4];
bool visited[N][N][4];

void solve()
{
    int w,h; cin>>h>>w;
    vector<string> S(h);
    int sr,sc,gr,gc;
    for(int i=0;i<h;i++)
    {
        cin>>S[i];
        for(int j=0;j<w;j++)
        {
            if(S[i][j]=='S'){sr=i,sc=j;}
            if(S[i][j]=='G'){gr=i,gc=j;}
        }
    }

    queue<State> q;  

    for(int i=0;i<4;i++)
    {
        int nx=sr+dx[i],ny=sc+dy[i];
        if(nx>=0&&nx<h&&ny>=0&&ny<w&&S[nx][ny]!='#')
        {
            if(!visited[nx][ny][i])
            {
                visited[nx][ny][i]=true;
                pre[nx][ny][i]={-1,i};
                q.push({nx,ny,i});
            }
        }
    }

    int end_x=-1,end_y=-1,end_d=-1;
    while(!q.empty())
    {
        State cur=q.front(); q.pop();
        if(cur.r==gr&&cur.c==gc)
        {
            end_x=cur.r;end_y=cur.c;end_d=cur.d;
            break;
        }

        char type=S[cur.r][cur.c];
        for(int i=0;i<4;i++)
        {
            if(type=='o'&&i!=cur.d) continue; //必须直行
            if(type=='x'&&i==cur.d) continue; //不能直行

            int nr=cur.r+dx[i],nc=cur.c+dy[i];
            if(nr>=0&&nr<h&&nc>=0&&nc<w&&S[nr][nc]!='#')
            {
                if(!visited[nr][nc][i])
                {
                    visited[nr][nc][i]=true;
                    pre[nr][nc][i]={cur.d,i};
                    q.push({nr,nc,i});
                }
            }
        }
    }

    if(end_x==-1) cout<<"No"<<endl;
    else
    {
        cout<<"Yes"<<endl;
        string res="";
        int cr=end_x,cc=end_y,cd=end_d;
        while(cd !=-1)
        {
            res+=dir_char[cd];
            pair<int, int> p=pre[cr][cc][cd];
            cr-=dx[cd]; cc-=dy[cd]; cd=p.first;
        }
        reverse(res.begin(),res.end());
        cout<<res<<endl;
    }
}


int main()
{
    solve();

    return 0;
}