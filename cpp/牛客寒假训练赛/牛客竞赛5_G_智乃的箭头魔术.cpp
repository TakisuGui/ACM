#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5 + 10;

const int MOD=1e5;

int fastmod (int a, int b) {
    int res = 1;
    while (b) {
        if (b & 1) res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}//快速取模

void solve()
{
   int n=0;
   string a;
   cin>>a;
   for(int i=0;i<a.size();i++)
   {
        if(a[i]=='0')
        {
            if(n==0)
            {
                n=3;
                cout<<"3";
            }
            else if(n==1)
            {
                n=2;
                cout<<"2";
            }
            else if(n==2)
            {
                n=1;
                cout<<"1";
            }
            else if(n==3)
            {
                n=0;
                cout<<"0";
            }
        }
        
        if(a[i]=='1')
        {
            if(n==0)
            {
                n=0;
                cout<<"0";
            }
            else if(n==1)
            {
                n=3;
                cout<<"3";
            }
            else if(n==2)
            {
                n=2;
                cout<<"2";
            }
            else if(n==3)
            {
                n=1;
                cout<<"1";
            }
        }
        if(a[i]=='2')
        {
            if(n==0)
            {
                n=1;
                cout<<"1";
            }
            else if(n==1)
            {
                n=0;
                cout<<"0";
            }
            else if(n==2)
            {
                n=3;
                cout<<"3";
            }
            else if(n==3)
            {
                n=2;
                cout<<"2";
            }
        }
        if(a[i]=='3')
        {
            if(n==0)
            {
                n=2;
                cout<<"2";
            }
            else if(n==1)
            {
                n=1;
                cout<<"1";
            }
            else if(n==2)
            {
                n=0;
                cout<<"0";
            }
            else if(n==3)
            {
                n=3;
                cout<<"3";
            }
        }
        if(a[i]=='4')
        {
            if(n==0)
            {
                n=1;
                cout<<"1";
            }
            else if(n==1)
            {
                n=2;
                cout<<"2";
            }
            else if(n==2)
            {
                n=3;
                cout<<"3";
            }
            else if(n==3)
            {
                n=0;
                cout<<"0";
            }
        }
        if(a[i]=='5')
        {
            if(n==0)
            {
                n=3;
                cout<<"3";
            }
            else if(n==1)
            {
                n=0;
                cout<<"0";
            }
            else if(n==2)
            {
                n=1;
                cout<<"1";
            }
            else if(n==3)
            {
                n=2;
                cout<<"2";
            }
        }
   }
    


}

signed main()
{ 
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    solve();

    return 0;
}