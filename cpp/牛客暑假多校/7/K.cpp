#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
using ull=unsigned long long;
#define endl "\n"
#define int ll

vector<vector<string>> text(21);

string get_abbr(vector<string>& words,int used)
{
    string ans;
    for(int i=0;i<(int)words.size();i++)
    {
        if(i<used) ans+=words[i];
        else ans+=words[i][0];
    }
    return ans;
}


void solve()
{
    int n; cin>>n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    
    for(int i=0;i<n;i++)
    {
        string line; getline(cin,line);
        stringstream ss(line);
        string word;
        while(ss>>word)
        {
            text[i].push_back(word);
        }
    }

    vector<int> used(n,0);
    
    while(true)
    {
        vector<string> abbr(n);
        unordered_map<string,int> mp;
        for(int i=0;i<n;i++)
        {
            abbr[i]=get_abbr(text[i],used[i]);
            mp[abbr[i]]++;
        }

        bool changed=false;
        for(int i=0;i<n;i++)
        {
            if(mp[abbr[i]]>1)
            {
                used[i]++;
                changed=true;
            }
        }

        if(!changed)
        {
            for(int i=0;i<n;i++) cout<<abbr[i]<<endl;
            break;
        }
    }
}


signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll t; t=1;
    while(t--)
    {
        solve();
    }

    return 0;
}