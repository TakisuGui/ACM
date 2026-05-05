#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    int t; cin>>t;
    while(t--)
    {
        int n,d; cin>>n>>d;

        vector<int> a(n+1),b(n+1);
        for(int i=1;i<=n;i++) cin>>a[i];
        for(int i=1;i<=n;i++) cin>>b[i];
        deque<pair<int,int>> dq;
        ll total=0;

        for(int day=1;day<=n;day++)
        {
            //早上买鸡蛋
            dq.push_back({day,a[day]});
            total+=a[day];

            //中午用鸡蛋
            int need=b[day];
            while(need>0&&!dq.empty())
            {
                int &has=dq.front().second;
                int use=min(need,has);
                has-=use;
                total-=use;
                need-=use;

                if(has==0) dq.pop_front();
            }

            //晚上丢弃
            while(!dq.empty()&&day-dq.front().first>=d)
            {
                total-=dq.front().second;
                dq.pop_front();
            }
        }

        cout<<total<<endl;
    }
    return 0;
}
