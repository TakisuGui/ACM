#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    int m, n; cin>>m>>n;
    char text[11][11];
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(i==0||i==m-1) text[i][j]='#';
            else if(j==0||j==n-1) text[i][j]='#';
            else text[i][j]='.';
        }
    }

    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<text[i][j];
        }
        cout<<endl;
    }

    return 0;
}