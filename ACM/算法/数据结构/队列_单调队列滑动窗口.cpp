#include<bits/stdc++.h>
using namespace std;

const int N=1e6+10;

int n,k;
deque<int> q;
int a[N];
int tp[N];

void find_min()//单调递增
{
    for(int i=1;i<=n;i++)
    {
        while(!q.empty()&&a[q.back()]>=a[i])q.pop_back();

        q.push_back(i);

        if(q.back()-q.front()+1>k)q.pop_front();

        if(i>=k) cout<<a[q.front()]<<" ";
    }
    cout<<endl;
}

void find_max()//单调递减
{
    for(int i=1;i<=n;i++)
    {
        while(!q.empty()&&a[q.back()]<=a[i])q.pop_back();

        q.push_back(i);

        if(q.back()-q.front()+1>k)q.pop_front();

        if(i>=k) cout<<a[q.front()]<<" ";
    }
    cout<<endl;
}


int main()
{
    cin>>n>>k;
    for(int i=1;i<=n;i++)cin>>a[i];

    find_min();
    q.clear();
    find_max();

    return 0;
}
