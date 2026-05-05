#include<bits/stdc++.h>
using namespace std;

const int N=1e5+10;

int n;
vector<int> str;
bool st[N];

void dfs(int place)
{
    if(place>n)
    {
        for(auto x:str)
        {
            printf("%5.d",x);
        }

        cout<<endl;
        return;
    }


    for(int i=1;i<=n;i++)
    {
        if(!st[i])
        {
            str.push_back(i);
            st[i]=true;

            dfs(place+1);

            str.pop_back();
            st[i]=false;
        }
    }
}


int main()
{
    cin>>n;

    dfs(1);


    return 0;
}