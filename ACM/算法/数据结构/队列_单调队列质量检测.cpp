#include<bits/stdc++.h>
using namespace std;

const int c=1e6+10;

int N,M;
int a[c];
deque<int> q;

int main()
{
    cin>>N>>M;

    for(int i=0;i<N;i++)cin>>a[i];

    for(int i=0;i<N;i++)
    {
        while(!q.empty()&&a[q.back()]>=a[i])q.pop_back();

        q.push_back(i);

        if(q.back()-q.front()+1>M)q.pop_front();

        if(i>=M-1)cout<<a[q.front()]<<endl;
    }

    return 0;
}