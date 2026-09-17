#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int n,s,a,b;

vector<pair<int,int>> apple;

bool compare(const pair<int,int>&a,const pair<int,int>&b)
{
    return a.second<b.second;
}

int main()
{
    cin>>n>>s;
    cin>>a>>b;
    int high=a+b;
    int ans=0;

    apple.resize(n);
    for(int i=0;i<n;i++) cin>>apple[i].first>>apple[i].second;

    sort(apple.begin(),apple.end(),compare);

    for(int i=0;i<n;i++)
    {
        if(high>=apple[i].first&&s-apple[i].second>=0)
        {
            ans++;
            s-=apple[i].second;
        }
    }

    cout<<ans<<endl;

    return 0;
}