#include<bits/stdc++.h>
using namespace std;
using ull=unsigned long long;
const int N=3e4+10;
const int base=499;


class Solution {
public:
    
    vector<ull> pow=vector<ull>(N,0);
    vector<ull> hash=vector<ull>(N,0);
    
    vector<int> findSubstring(string s, vector<string>& words) 
    {
        vector<int> ans;

        unordered_map<ull,int> mp;
        for(auto& key : words)
        {
            ull v=get_hash(key);
            mp[v]++;
        }

        int n=s.size();
        build(s,n);
        int len=words[0].size();
        int words_nums=words.size();
        int all_len=len*words_nums;

        for(int i=0;i<len&&i+all_len<=n;i++)
        {
            unordered_map<ull,int> window;
            int debt=words_nums;

            for(int l=i,r=i+len,part=0;part<words_nums;l+=len,r+=len,part++)
            {
                ull cur=get_hash(l,r);
                window[cur]++;

                if(mp.count(cur)&&window[cur]<=mp[cur]) debt--;
            }
                if(debt==0) ans.push_back(i);


                for(int l1=i,r1=i+len,l2=i+all_len,r2=i+all_len+len;
                    r2<=n;
                    l1+=len,r1+=len,l2+=len,r2+=len)
                {
                    ull out=get_hash(l1,r1),in=get_hash(l2,r2);

                    window[out]--;
                   int mapOutCount=mp.count(out) ? mp[out] : 0;
                    if(window[out]<mapOutCount) debt++;

                    window[in]++;
                    int mapInCount=mp.count(in) ? mp[in] : 0;
                    if(window[in]<=mapInCount) debt--;
                    
                    if(debt==0) ans.push_back(r1);
                }
            
        }
        return ans;
    }


    void build(string s,int n)
    {
        pow[0]=1;
        for(int i=1;i<=n;i++) pow[i]=pow[i-1]*base;
        
        hash[0]=s[0]-'a'+1;
        for(int i=1;i<n;i++) hash[i]=hash[i-1]*base+s[i]-'a'+1;
    }

    ull get_hash(int l,int r)
    {
        ull ans=hash[r-1];
        if(l>0) ans-=hash[l-1]*pow[r-l];
        return ans;
    }

    ull get_hash(string s)
    {
        int n=s.size();
        ull ans=s[0]-'a'+1;
        for(int i=1;i<n;i++) ans=ans*base+s[i]-'a'+1;
        return ans;
    }
};