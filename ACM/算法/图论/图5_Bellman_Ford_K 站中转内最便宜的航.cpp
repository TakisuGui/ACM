#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int> cur(n,INT_MAX);
        cur[src]=0;

        for(int i=0;i<=k;i++)
        {
            vector<int> next=cur;

            for(auto edge:flights)
            {
                int from=edge[0],to=edge[1],price=edge[2];

                if(cur[from]!=INT_MAX)
                {
                    next[to]=min(next[to],cur[from]+price);
                }
            }

           cur=move(next); //cur=next;
        }
        return cur[dst]==INT_MAX ? -1 : cur[dst];
    }
};