#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n"
#define int ll
const int N=2e5+10;

struct Point {int r,c;};

bool check_(vector<Point>& pts)
{
    if(pts.size()<3) return false;

    bool diag1=true,diag2=true;
    int rowCount[4]={0},colCount[4]={0};

    for(auto p : pts)
    {
        rowCount[p.r]++;
        colCount[p.c]++;
        if (p.r!=p.c) diag1=false;
        if (p.r+p.c!=4) diag2=false;
    }

    for(int i=1;i<=3;i++)
    {
        if (rowCount[i]==3||colCount[i]==3) return true;
    }
    if(diag1||diag2) return true;

    return false;
}

void solve() 
{
    int n; cin>>n;
    vector<Point> my(n),op(n);
    bool occupied[4][4]={false};

    for(int i=0;i<n;i++)
    {
        cin>>my[i].r>>my[i].c;
        occupied[my[i].r][my[i].c]=true;
    }
    for(int i=0;i<n;i++) 
    {
        cin>>op[i].r>>op[i].c;
        occupied[op[i].r][op[i].c]=true;
    }

    for (int r=1; r<=3; r++)
    {
        for (int c=1; c<=3;c++)
        {
            if(!occupied[r][c])
            {
                vector<Point> next_my;
                if (n<3)
                {
                    next_my=my;
                    next_my.push_back({r, c});
                } 
                else 
                {
                    for(int i=1;i<3;i++) next_my.push_back(my[i]);
                    next_my.push_back({r, c});
                }

                if (check_(next_my))
                {
                    cout<<r<<" "<<c<<endl;
                    return;
                }
            }
        }
    }
    cout<<"Columbina Hyposelenia"<<endl;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t; cin>>t;
    while(t--)
    {
        solve();
    }

    return 0;
}