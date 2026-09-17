#include <bits/stdc++.h>
using namespace std;

const int N=1e5+10;

int n,m;

queue<int>a;

int main()
{
    cin>>n>>m;

    for(int i=1;i<=n;i++) a.push(i);

    int count=0;
    int size=n;

    while(size>1)
    {
        count++;

        auto out=a.front();
        a.pop();

        if(count!=m)
        {
            a.push(out);
        }

        else
        {
            count=0;
            size--;
            cout<<out<<" ";
        }
    }

    cout<<a.front();

    return 0;
}