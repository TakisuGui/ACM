#include <bits/stdc++.h>
using namespace std;
int n,m;
int x[100005],y[100005];

int main(){
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int xi,yi;
        cin>>xi>>yi;
        x[xi]++;
        y[yi]++;
    }
    sort(x,x+n+1,greater<int>());
    sort(y,y+n+1,greater<int>());
    int res=max(x[0],y[0]);
    cout<<n-res<<endl;
}
