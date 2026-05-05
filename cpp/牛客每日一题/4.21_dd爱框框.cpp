#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n"
const int N=1e7+10;
int a[N];

priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> heap_small;//小跟堆

void solve()
{
    int n,x; cin>>n>>x;
    for(int i=1;i<=n;i++) cin>>a[i];

    int l=1,r=1; ll sum=0;

    while(r<=n)
    {
        if(sum+a[r]<x)
        {
            sum+=a[r];
            r++;
        }
        else
        {
            int dis=r-l+1;
            heap_small.push({dis,{l,r}});

            sum-=a[l];
            l++;
        }
    }

    cout<<heap_small.top().second.first<<" "<<heap_small.top().second.second<<endl;
}


int main()
{
    solve();

    return 0;
}