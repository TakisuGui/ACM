#include<bits/stdc++.h>
using namespace std;


#define int long long

int n,m;
int squ=0,rec=0;


int main()
{
    cin>>n>>m;

    int k=1;//正方形边长

    while(k<=n&&k<=m){
        squ=squ+(n-k+1)*(m-k+1);
        k++;
    }

    int x=1,y=1;//长方形长和宽

    while(x<=n){
        y=1;
        while(y<=m){
            rec=rec+(n-x+1)*(m-y+1);
            y++;
        }

        x++;
    }

    rec=rec-squ;


    cout<<squ<<" "<<rec;



    return 0;
}