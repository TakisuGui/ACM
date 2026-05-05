#include<bits/stdc++.h>
using namespace std;


const int N=1e5+10;

int a[N];
int n;
int temp[N];//合并俩个有序数组的临时数组

void merge_sort(int left,int right){

    if(left>=right)return;

    //1.先一分为二
    int mid=(left + right)>> 1;//分成[left,mid]和[mid+1.right]两个区间

    //2.先让左右区间有序
    merge_sort(left,mid);
    merge_sort(mid+1,right);

    //3.合并两个有序数组
    int cur1=left;int cur2=mid+1;int i=left;

    while(cur1<=mid&&cur2<=right){

        if(a[cur1]<=a[cur2]) temp[i++]=a[cur1++];
        else temp[i++]=a[cur2++];
    }

    while(cur1<=mid) temp[i++]=a[cur1++];
    while(cur2<=right) temp[i++]=a[cur2++];

    for(int j=left;j<=right;j++){

        a[j]=temp[j];
    }

}





int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }

        merge_sort(1,n);

        for(int i=1;i<=n;i++){
        cout<<a[i]<<" ";

    }


    return 0;
}