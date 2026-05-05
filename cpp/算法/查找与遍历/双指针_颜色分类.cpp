#include<bits/stdc++.h>
using namespace std;

int n;

void sortcolors(vector<int>& nums){
    int left=1,right=nums.size()-1;
    int i=1;

    while(i<=right)
    {
        if(nums[i]==0){
            swap(nums[i],nums[left]);
            i++;left++;
        }

        else if(nums[i]==1){
            i++;
        }

        else{
            swap(nums[right],nums[i]);
            right--;
        }
    }

}


int main(){
    cin>>n;
    vector<int> nums(n+1);

    for(int i=1;i<=n;i++)cin>>nums[i];

    sortcolors(nums);


    for(int i=1;i<=n;i++)cout<<nums[i]<<" ";


    return 0;
}