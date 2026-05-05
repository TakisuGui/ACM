#include<bits/stdc++.h>
using namespace std;

const int N=1e5+10;

int n;
int a[N];


int main()
{
    int t;cin>>t;
    while(t--)
    {
        cin>>n;
        for(int i=1;i<=n;i++)cin>>a[i];

        //初始化
        int left=1,right=1,ans=0;
        unordered_map<int,int> mp;//哈希表
        //int mp[N];

        while(right<=n)
        {
            mp[a[right]]++;//进窗口

            //判断窗口合法
            while(mp[a[right]]>1)
            {
                //出窗口
                mp[a[left]]--;
                left++;
            }

            //更新结果
            ans=max(ans,right-left+1);
            right++;

        }

        cout<<ans<<endl;
    }

    return 0;
}
