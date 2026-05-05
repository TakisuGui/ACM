#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long ll;
ll f[17];

ll rev(ll x)
{
    ll res=0;
    while(x)
    {
        res=res*10+(x%10);
        x/=10;
    }

    return res;
}

void ini()
{
    f[0]=1;
    for(int i=1;i<=16;i++) f[i]=f[i-1]*10;
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int t;cin>>t;
    ini();
    while(t--)
    {
        ll r,l;
        ll ans=0;
        cin>>l>>r;
        
        ans=max({ans,rev(r),rev(l)});
        if(r-1>=l) ans=max(ans,rev(r-1));

        int wei_r=0,wei_l=0;
        ll temple_r=r,temple_l=l;
        int R[17]={0},L[17]={0};
        while(temple_r>0)
        {
            temple_r=temple_r/10;
            wei_r++;
        }
        while(temple_l>0)
        {
            temple_l=temple_l/10;
            wei_l++;
        }
 
        temple_r=r,temple_l=l;
        int i=0;
        while(temple_r>0)
        {
            R[i]=temple_r%10;
            i++;
            temple_r=temple_r/10;
        }
        int p=0;
        while(temple_l>0)
        {
            L[p]=temple_l%10;
            p++;
            temple_l=temple_l/10;
        }


        if(wei_r>wei_l)
        {
            bool first_wei=true;
            for(int k=wei_r-2;k>=0;k--)
            {
                
                if(R[k+1]!=1&&first_wei==true)
                {
                    R[k+1]--;
                    for(int j=k;j>=0;j--)
                    {
                        R[j]=9;
                    }
                    break;
                }

                first_wei=false;
                if(R[k]!=0)
                {
                    R[k]--;
                    for(int j=k-1;j>=0;j--)
                    {
                        R[j]=9;
                    }
                    break;
                }
            }
        }
        else
        {
            for(int k=wei_r-1;k>=0;k--)
            {
                if(R[k]!=L[k])
                {
                    R[k]--;
                    for(int j=k-1;j>=0;j--)
                    {
                        R[j]=9;
                    }
                    break;
                }
            }
        }

        ll stn=0;
            for(int q=0;q<=wei_r-1;q++)
            {
                stn+=R[q]*f[q];
            }

            if(stn >= l && stn <= r)
            ans=max(ans,rev(stn));

        for(ll h=r-1000;h<=r;h++) if(h>l) ans=max(ans,rev(h));

        cout<<ans<<endl;
    }
    
    return 0;
    
}