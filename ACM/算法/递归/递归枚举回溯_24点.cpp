#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const double EPS=1e-6;

bool solve24(vector<double> &nums)
{
    if(nums.size()==1)
    {
        if(abs(nums[0]-24)<EPS) return true;
        else return false;
    }

    int n=nums.size();
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(i==j) continue;

            double a=nums[i]; double b=nums[j];

            vector<double> remaining;
            for(int k=0;k<n;k++)
            {
                if(k!=i&&k!=j) remaining.push_back(nums[k]);
            }

            double new_num;

            new_num=a+b;
            remaining.push_back(new_num);
            if(solve24(remaining)) return true;
            remaining.pop_back();

            new_num=a-b;
            remaining.push_back(new_num);
            if(solve24(remaining)) return true;
            remaining.pop_back();

            new_num=b-a;
            remaining.push_back(new_num);
            if(solve24(remaining)) return true;
            remaining.pop_back();

            new_num=a*b;
            remaining.push_back(new_num);
            if(solve24(remaining)) return true;
            remaining.pop_back();

            if(abs(b)>EPS)
            {
                new_num=a/b;
                remaining.push_back(new_num);
                if(solve24(remaining)) return true;
                remaining.pop_back();
            }

            if(abs(a)>EPS)
            {
                new_num=b/a;
                remaining.push_back(new_num);
                if(solve24(remaining)) return true;
                remaining.pop_back();
            }

        }
    }
    return false;
}

int main()
{
    int t; cin>>t;
    while(t--)
    {
        vector<double> nums(4);
        for(int i=0;i<4;i++) cin>>nums[i];

        if(solve24(nums)) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}