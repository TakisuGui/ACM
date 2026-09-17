#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n"
#define int ll

bool is_vowel(char c)
{
    if(c=='a'||c=='e'||c=='i'||c=='o'||c=='u') return true;
    else return false;
}

void solve()
{
    string s; cin>>s;
    if(s.size()!=8)
    {
        cout<<"Well-Being"<<endl;
        return;
    }

    s=' '+s;
    for(int i=1;i<=8;i++)
    {
        if(i%2==1&&is_vowel(s[i]))
        {
            cout<<"Well-Being"<<endl;
            return;
        }
        if(i%2==0&&!is_vowel(s[i]))
        {
            cout<<"Well-Being"<<endl;
            return;
        }
    }

    cout<<"Suspected Virus"<<endl;
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