#include<bits/stdc++.h>
using namespace std;

const int N=10;

int a[N];
int n=5;
int t[N];


int calc(int x)
{
    int q=0;
    while(x)
    {
        q++;
        x=x&(x-1);
    }

    return q;

}

int main()
{
    int T;cin>>T;

    while(T--)
    {
        //清空之前数据
        memset(a,0,sizeof a);

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                char ch;cin>>ch;
                //取相反的值
                if(ch=='0')a[i]|=(1<<j);

            }
        }

        int ret=100;

        for(int st=0;st<32;st++){

            memcpy(t,a,sizeof a);
            int push=st;
            int cnt=0;

            for(int i=0;i<n;i++)
            {
                cnt=cnt+calc(push);

                t[i]=t[i]^push^(push>>1)^(push<<1);
                t[i]=t[i]&((1<<n)-1);

                t[i+1]^=push;

                push=t[i];
            }

            if(t[n-1]==0) ret=min(ret,cnt);

        }
        if(ret>6)cout<<-1<<endl;
        else cout<<ret<<endl;
    }



    return 0;
}
