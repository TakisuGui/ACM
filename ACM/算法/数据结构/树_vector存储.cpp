#include<bits/stdc++.h>
using namespace std;


const int N=1e5+10;


int n;
vector <int> edges[N];//vector数组存储树


int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int a,b;
        cin>>a>>b;
        //a和b之间有一条边

        edges[a].push_back(b);
        edges[b].push_back(a);
    }



    return 0;
}
