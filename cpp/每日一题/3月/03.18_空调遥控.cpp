#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e6+10;
int a[N];
deque<int> q;

int main()
{
    int n,p; cin>>n>>p;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+1+n);

    int ans=1,temp=1; q.push_back(a[1]);
    for(int i=2;i<=n;i++)
    {
        int top=q.front();

        while(a[i]-top>2*p)
        {
            q.pop_front();
            top=q.front();
            temp--;
        }

        q.push_back(a[i]);
        temp++;

        ans=max(ans,temp);
    }

    cout<<ans<<endl;

    return 0;
}