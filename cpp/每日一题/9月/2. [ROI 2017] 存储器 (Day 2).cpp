#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
using ull=unsigned long long;
#define endl "\n"
#define int ll
const int N=1e18;
const int MOD=998244353;

bool check(string s,int tar_type)
{
    vector<pair<int,int>> sf;
    int cnt=1,dex= s[0]=='+' ? 1 : 0;
    for(int i=1;i<s.size();i++)
    {
        if(s[i]!=s[i-1])
        {
            sf.push_back({cnt,dex});
            cnt=1;
            dex= s[i]=='+' ? 1 : 0;
        }
        else cnt++;
    }
    sf.push_back({cnt,dex});

    stack<pair<int,int>> st; st.push(sf[0]);

    for(int i=1;i<sf.size();i++)
    {
        auto [cur_len,cur_type]=sf[i];

        if(cur_type==tar_type)
        {
            while(!st.empty())
            {
                auto [has_len,has_type]=st.top();
                if((has_type==tar_type) || ((has_type!=tar_type) && (has_len<cur_len)))
                {
                    cur_len+=has_len;
                    st.pop();
                }
                else break;
            }
            st.push({cur_len,cur_type});
        }
        else
        {
            if(!st.empty() && st.top().second==tar_type && st.top().first > cur_len)
            {
                auto [has_len,has_type]=st.top(); st.pop();
                int new_len=has_len+cur_len;
                while(!st.empty() &&( st.top().second==tar_type || new_len > st.top().first))
                {
                    new_len+=st.top().first;
                    st.pop();
                }
                st.push({new_len,tar_type});
            }
            else st.push({cur_len,cur_type});
        }
    }
    return (st.size()==1&&st.top().second==tar_type);
}

void solve()
{
    string s,t; cin>>s>>t;
    vector<pair<int,int>> et;
    vector<int> diff_t;

    int cnt=1,dex= t[0]=='+' ? 1 : 0;
    for(int i=1;i<t.size();i++)
    {
        if(t[i]!=t[i-1])
        {
            diff_t.push_back(i);
            et.push_back({cnt,dex});
            cnt=1;
            dex= t[i]=='+' ? 1 : 0;
        }
        else cnt++;
    }
    et.push_back({cnt,dex});

    for(int i=0;i<diff_t.size();i++)
    {
        int x=diff_t[i];  // 分割位置
        int prev_type=et[i].second;  // 上一个片段的类型

        if((s[x]==s[x-1]) || (prev_type==1&&s[x]=='+') || (prev_type==0&&s[x]=='-'))
        {
            cout<<"No"<<endl;
            return;
        }
    }
    
    int start=0;
    for(int i=0;i<et.size();i++)
    {
        auto [len,tar_type]=et[i];
        string sub_s=s.substr(start,len);

        if(!check(sub_s,tar_type))
        {
            cout<<"No"<<endl;
            return;
        }
        start+=len;
    }
    cout<<"Yes"<<endl;
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