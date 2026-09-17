#include<bits/stdc++.h>
using namespace std;

string text;

int main()
{
    cin>>text; 
    text=' '+text;
    int length=text.size()-1;

    int dp[length+3][length+3]={0};

    for(int len=2;len<=length;len++)
    {
        for(int i=1;i+len-1<=length;i++)
        {
            int j=i+len-1;
            
            if(text[i]==text[j]) dp[i][j]=dp[i+1][j-1];
            else dp[i][j]=min(dp[i+1][j]+1,dp[i][j-1]+1);
        }
    }

    cout<<dp[1][length]<<endl;

    return 0;
}