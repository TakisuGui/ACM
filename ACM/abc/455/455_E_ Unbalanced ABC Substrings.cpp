#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=3e5+10;


void solve()
{
    int n; cin>>n;
    string s; cin>>s;

    ll total=1ll*(n+1)*n/2;

    map<int,ll> mpAB,mpBC,mpAC;
    map<pair<int,int>,ll>mpABC;

    mpAB[0]=1;
    mpBC[0]=1;
    mpAC[0]=1;
    mpABC[{0,0}]=1;

    int curA=0,curB=0,curC=0;

    for(char c:s)
    {
        if (c=='A') curA++;
        else if (c=='B') curB++;
        else if (c=='C') curC++;

        mpAB[curA-curB]++;
        mpBC[curB-curC]++;
        mpAC[curA-curC]++;
        mpABC[{curA-curB,curB-curC}]++;
    }

    auto count_pairs=[](ll k)
    {
        return k*(k-1)/2;
    };

    ll pAB=0,pBC=0,pAC=0,pABC=0;

    for (auto const& [val, count] : mpAB) pAB+=count_pairs(count);
    for (auto const& [val, count] : mpBC) pBC+=count_pairs(count);
    for (auto const& [val, count] : mpAC) pAC+=count_pairs(count);
    for (auto const& [val, count] : mpABC) pABC+=count_pairs(count);

    ll invalid=pAB+pBC+pAC-2*pABC;

    cout<<total-invalid<<endl;
}



int main()
{

    ios::sync_with_stdio(false);
    cin.tie(0);

    int t; t=1;
    while(t--)
    {
        solve();
    }

    return 0;
}