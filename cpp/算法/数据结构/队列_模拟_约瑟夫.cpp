#include<bits/stdc++.h>
using namespace std;

const int N=1e5+10;

int k;

int tp[N];
int np[N];

int main()
{
    cin>>k;
    int ans;

    for(ans=1;;ans++){

    memset(np,0,sizeof np);
    queue<int> a;
    
    for(int i=1;i<=k;i++)
    {
        a.push(i);
        //标记好人
        tp[i]=1;
        np[1]++;//好人总数
    }
    for(int i=k+1;i<=2*k;i++)
    {
        a.push(i);
        //标记坏人
        tp[i]=0;
        np[0]++;//坏人总数
    }

    int count=0;
    int sa=0;

        do
        {
            count++;

            auto out=a.front();
            a.pop();

            if(count!=ans)
            {
               a.push(out);
            }   
            else
            {
               if(tp[out]==1)
               {
                  sa=1;
                  break;
               }

               else
               {
                  count=0;
                  np[0]--;
               }
            }

        }while(np[0]>0);

        if(sa==1)continue;
        else
        {
            cout<<ans<<endl;
            return 0;
        }

    }

}