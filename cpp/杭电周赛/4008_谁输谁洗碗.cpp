#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=15;

struct Guess
{
    string s;
    int k;
};

string to_string_4(int num)
{
    string res="";
    res+=(num/1000)+'0';
    res+=(num/100%10)+'0';
    res+=(num/10%10)+'0';
    res+=(num%10)+'0';
    return res;
}

void solve()
{
    int n; cin>>n;
    vector<Guess> guesses(n);
    for(int i=0;i<n;i++) cin>>guesses[i].s>>guesses[i].k;

    for(int i=0; i<=9999;i++)
    {
        string target=to_string_4(i);
        bool ok=true;

        for(int j=0; j<n;j++)
        {
            int match_cnt=0;
            for(int p=0;p<4;p++)
                if(target[p]==guesses[j].s[p])match_cnt++;
            
            if(match_cnt!=guesses[j].k)
            {
                ok=false;
                break;
            }
        }

        if (ok)
        {
            cout<<target<<"\n";
            return;
        }
    }

}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin>>t;
    while(t--)
    {
        solve();
    }

    return 0;
}