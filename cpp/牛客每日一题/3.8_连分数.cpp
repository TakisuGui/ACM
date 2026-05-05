#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll gcd(ll a,ll b)
{
    if(b==0) return a;
    else return gcd(b,a%b);
}

vector<ll> fraction(ll p,ll q)
{
    vector<ll> parts;
    while(q!=0)
    {
        ll inte_part=p/q;
        parts.push_back(inte_part);

        ll remain_p=p-inte_part*q;
        p=q;
        q=remain_p;
    }

    return parts;
}

string text(const vector<ll> &parts,int dex)
{
    if(dex==parts.size()-1) return to_string(parts[dex]);

    else if(dex==parts.size()-2) return to_string(parts[dex])+"+1/"+to_string(parts[dex + 1]);
    
    else return  to_string(parts[dex])+"+1/{"+text(parts,dex+1)+"}";
}

void slove()
{
    ll p,q; cin>>p>>q;
    ll or_p=p,or_q=q;

    ll g=gcd(p,q);
    p/=g,q/=g;

    vector<ll> parts=fraction(p,q);

    cout<<or_p<<"/"<<or_q<<" = ";

    if(parts.size()==1) cout<<parts[0]<<endl;
    else
    {
        string ans=text(parts,0);
        cout<<ans<<endl;
    }
}

int main()
{
    int t; cin>>t;
    while(t--)
    {
        slove();
    }

    return 0;
}