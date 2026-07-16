#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    int n; cin>>n;
    string s; cin>>s;

    string ans;
    for(char c:s)
    {
        ans+=c;
        if(ans.size()>=2&&ans.substr(ans.size()-2)=="mo")
        {
            ans.pop_back();
            ans.pop_back();
        }
        if(ans.size()>=3&&ans.substr(ans.size()-3)=="niu")
        {
            ans.pop_back();
            ans.pop_back();
            ans.pop_back();
        }
    }

    cout<<(ans=="" ? "Yes" : "No")<<endl;

    return 0;
}