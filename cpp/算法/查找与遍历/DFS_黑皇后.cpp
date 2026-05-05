#include<bits/stdc++.h>
using namespace std;

const int N=20;

int n;
int col[N];
int diag1[2*N];//主对角线
int diag2[2*N];//副对角线
int queen[N];//第i行皇后应该放在哪列
int ans;
vector< vector<int> > solutions;

void dfs(int row)
{
    if(row>n)
    {
        ans++;
        if(ans<=3)
        {
            vector<int> temp_solutions;
            for(int i=1;i<=n;i++) temp_solutions.push_back(queen[i]);
            solutions.push_back(temp_solutions);
        }

        return;
    }

    for(int j=1;j<=n;j++)
    {
        if(!col[j]&&!diag1[row-j+n]&&!diag2[row+j])
        {
            queen[row]=j;
            col[j]=1;
            diag1[row-j+n]=1;
            diag2[row+j]=1;

            dfs(row+1);

            //回溯
            col[j]=0;
            diag1[row-j+n]=0;
            diag2[row+j]=0;

        }
    }
}

int main()
{
    cin>>n;

    memset(col, 0, sizeof(col));
    memset(diag1, 0, sizeof(diag1));
    memset(diag2, 0, sizeof(diag2));

    dfs(1);

    for(int i=0;i<min(3,(int)solutions.size());i++)
    {
        for(int j=0;j<n;j++)
        {
            if (j==0) cout<<solutions[i][j];
            else cout<<" "<<solutions[i][j];
        }

        cout<<endl;
    }

    cout<<ans<<endl;

    return 0;
}
