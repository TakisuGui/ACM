#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
using ull=unsigned long long;
#define endl "\n"
#define int ll
const int N=300000*31+5;


void solve()
{
    int n; cin>>n;
    vector<int> a(n+3);
    for(int i=1;i<=n;i++) cin>>a[i];

    vector<int> dex_0; dex_0.push_back(0);
    for(int i=1;i<=n;i++) if(a[i]==0) dex_0.push_back(i);
    dex_0.push_back(n+1);

    int l=dex_0[0],r; int max_cnt_2=0; int ans_l=n,ans_r=n+1;
    for(int i=1;i<dex_0.size();i++)
    {
        r=dex_0[i];
        int neg=0; int cnt_2=0;
        for(int j=l+1;j<r;j++) 
        {
            if(a[j]<0) neg++;
            if(abs(a[j])==2) cnt_2++;
        }

        if(neg%2==0)
        {
            if(cnt_2>max_cnt_2)
            {
                max_cnt_2=cnt_2;
                ans_l=l,ans_r=r;
            }
        }
        else
        {
            int temp_cnt_2=cnt_2;
            int temp_l=l,temp_r=r;
            for(int j=l+1;j<r;j++)
            {
                if(abs(a[j])==2) temp_cnt_2--;
                if(a[j]<0)
                {
                    temp_l=j;
                    break;
                }
            }
            if(temp_cnt_2>max_cnt_2)
            {
                max_cnt_2=temp_cnt_2;
                ans_l=temp_l,ans_r=temp_r;
            }

            temp_cnt_2=cnt_2;
            temp_l=l,temp_r=r;
            for(int j=r-1;j>l;j--)
            {
                if(abs(a[j])==2) temp_cnt_2--;
                if(a[j]<0)
                {
                    temp_r=j;
                    break;
                }
            }
            if(temp_cnt_2>max_cnt_2)
            {
                max_cnt_2=temp_cnt_2;
                ans_l=temp_l,ans_r=temp_r;
            }
        }
        l=r;
    }

    cout<<ans_l<<" "<<n-ans_r+1<<endl;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll t; cin>>t;
    while(t--)
    {
        solve();
    }

    return 0;
}