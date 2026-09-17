#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1000000;

vector<int> sum_mu(N+1,0);

// mu[1]=1
// mu[i]=-1 如果 i 是质数
// mu[i]=1  如果 i 是 多个 互不相同的 质数 相乘得到
// mu[i]=0  如果 i 包含平方因子
pair<vector<bool>, vector<int>> get_prime_and_mu()
{
    vector<bool> prime(N+1,true);
    vector<int> mu(N+1,1);

    prime[0]=prime[1]=false;

    for(int p=2;p<=N;p++)
    {
        if(prime[p])
        {
            for(int j=p;j<=N;j+=p)
            {
                if(j>p) prime[j]=false;
                mu[j]=-mu[j]; 
                // 如果是 质数 翻转奇数次 变为 -1
                // 如果是 合数 翻转偶数次 变为 1
            }

            for(ll j=1ll*p*p;j<=N;j+=p*p) mu[j]=0; // 全部 p^2 的倍数
        }
    }

    return{prime,mu};
}


//       min(n,m)
// ans=  xigma    mu(d)*floor(n/d)*floor(m/d)
//       d=1


int solve(int n,int m)
{
    int ans=0;
    int lim=min(n,m);

    for(int l=1,r=0;l<=lim;l=r+1)
    {
        r=min(n/(n/l),m/(m/l));

        ans+=1ll*(sum_mu[r]-sum_mu[l-1])*(n/l)*(m/l);
    }
    return ans;
}

int main()
{
    auto [prime, mu]=get_prime_and_mu();

    for (int i=1;i<=N;i++) sum_mu[i]=sum_mu[i-1]+mu[i];
    
    int t; cin>>t;
    while(t--)
    {
        int n,m,d; cin>>n>>m>>d;
        cout<<solve(n/d,m/d)<<endl;
    }

    return 0;
}