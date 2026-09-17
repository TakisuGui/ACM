#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int x,y,z,n;

int main()
{
    cin>>x>>y>>z>>n;

    char major[x][y];
    memset(major,'.',sizeof major);
    char left[y][z];
    memset(left,'.',sizeof left);
    char uppon[x][z];
    memset(uppon,'.',sizeof uppon);

    while(n--)
    {
        int x_dex,y_dex,z_dex;
        cin>>x_dex>>y_dex>>z_dex;

        x_dex--,y_dex--,z_dex--;

        major[x_dex][y_dex]='x';
        left[y_dex][z_dex]='x';
        uppon[x_dex][z_dex]='x';
    }

    for(int i=y-1;i>=0;i--)
    {
        for(int j=0;j<x;j++) cout<<major[j][i];
        cout<<" ";
        for(int j=0;j<z;j++) cout<<left[i][j];
        cout<<endl;
    }
    cout<<endl;

    for(int i=0;i<z;i++)
    {
        for(int j=0;j<x;j++) cout<<uppon[j][i];
        cout<<endl;
    }

    return 0;
}