#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n"
#define int ll
const int N=2e5+10;

void solve() 
{
    string s; cin>>s;
    int n=s.length();
    
    vector<int> starts;
    for(int i=0; i+6<n;++i)
    {
        if (s.compare(i,7,"execute")==0) starts.push_back(i);
    }

    if (starts.empty()) { cout<<s<<endl; return; }

    vector<vector<int>> chains;
    vector<int> current_chain;
    current_chain.push_back(starts[0]);
    for (size_t i = 1; i < starts.size(); ++i) 
    {
        if (starts[i] == starts[i - 1] + 6) {
            current_chain.push_back(starts[i]);
        } else {
            chains.push_back(current_chain);
            current_chain.clear();
            current_chain.push_back(starts[i]);
        }
    }
    chains.push_back(current_chain);

    for (const auto& chain : chains) {
        int k = (int)chain.size();
        if (k % 2 == 0) {
            // 偶数链：必须全部使用“桥梁”位置（索引+6）来保证最少修改
            for (int i = 0; i <= k - 2; i += 2) {
                s[chain[i] + 6] = '1';
            }
        } else {
            // 奇数链：修改第一个 e (索引+0)，剩下部分按偶数链处理
            // 这样既满足了最少修改次数 (k+1)/2，又保证了字典序最小
            s[chain[0]] = '1';
            for (int i = 1; i <= k - 2; i += 2) {
                s[chain[i] + 6] = '1';
            }
        }
    }
    
    cout << s << endl;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t; cin>>t;
    while(t--)
    {
        solve();
    }

    return 0;
}