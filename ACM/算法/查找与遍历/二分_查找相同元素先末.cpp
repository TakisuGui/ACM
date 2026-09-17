#include<bits/stdc++.h>
using namespace std;

const int N=1e5+10;

int num[N];
int n,target;


//求起始位置
int front()
{
    int left=1,right=n;
    while(left<right)
    {
        int mid=(left+right)/2;
        
        if(num[mid]>=target)right=mid;
        
        else left=mid+1;
    }

    //判断
    if(num[left]==target) return left;
    else return -1;

}

//求最终位置
int last()
{
    int left=1,right=n;
    while(left<right)
    {
        int mid=(left+right+1)/2;

        if(num[mid]>target)right=mid-1;
        else left=mid;
    }

    if(target==num[right]) return right;
    else return -1;
}


int main()
{
    cin>>n>>target;
    for(int i=1;i<=n;i++)cin>>num[i];

    int p=front();

    int q=last();

    auto s=lower_bound(num+1,num+n+1,target);
    auto t=upper_bound(num+1,num+n+1,target);

    cout<<s-num<<","<<t-num-1<<endl;

    if(p==-1||q==-1)cout<<"-1,-1"<<endl;
    else cout<<p<<","<<q<<endl;

    return 0;
}