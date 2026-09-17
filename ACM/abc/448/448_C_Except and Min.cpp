#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

priority_queue<pair<int, int>,vector<pair<int, int>>,greater<pair<int, int>>> heap_small;//小跟堆

int n,q;
bool removed[300005];

int main()
{
    cin>>n>>q;

    for(int i=1;i<=n;i++)
    {
        int x; cin>>x;
        heap_small.push({x,i});
    }

    while(q--)
    {      
        int k; cin>>k;
        vector<int> remove_list(k);

        for(int i=0;i<k;i++)
        {
            cin>>remove_list[i];
            removed[remove_list[i]]=true;
        }

        vector<pair<int, int>> temp; 

        while(1)
        {

            auto top=heap_small.top();
            if(removed[top.second])
            {
                heap_small.pop();
                temp.push_back(top);
            }

            else
            {
                cout<<top.first<<"\n";
                break;
            }
        }

        for(auto& p:temp)
        {
            heap_small.push(p);
        }

        for(int idx:remove_list) removed[idx]=false;
    }

    return 0;
}