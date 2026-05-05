#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const int N=2e5+10;

LL n,m;
LL a[N];


int main()
{
    cin>>n>>m;
    vector<int> len(n);//存a的位数

    for(LL i=0;i<n;i++)
    {
        cin>>a[i];

        //预处理a[i]的位数
        if(a[i]==0) len[i]=1;
        else
        {
            LL temple=a[i];
            int tp_len=0;
            while(temple>0)
            {
                tp_len++;
                temple/=10;
            }

            len[i]=tp_len;
        }
    }

    //预处理10的次幂的m(mod)
    vector<LL> mod_10(11);
    mod_10[0]=1%m;
    for(int i=1;i<=10;i++)  mod_10[i]=(mod_10[i-1]*10)%m;


    //创建11个哈希表，第i个哈希表存储{a[n]*pow(10,i)}%m
    unordered_map<LL,int> cou[11];
    
    for(LL i=0;i<n;i++)
    {
        LL ai_mod=a[i]%m;
        for(int l=1;l<=10;l++)
        {
            LL value = (ai_mod*mod_10[l])%m;
            cou[l][value]++;
        }
    }

    LL ans=0;

    for(int j=0;j<n;j++)
    {
        int l=len[j];
        LL need=(-a[j])%m;
        if(need<0) need+=m;

        if(cou[l].count(need))  ans+=cou[l][need];
    }

     cout << ans << endl;
    
    return 0;
    
}