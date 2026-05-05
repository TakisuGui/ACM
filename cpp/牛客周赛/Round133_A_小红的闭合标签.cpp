#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int n;
string s;

int main()
{
    cin>>n>>s;
    bool sert=false;
    for(int i=0;i<n;i++)
    {
        if(sert)
        {
            cout<<"/";
            sert=false;
        }
        if(s[i]=='<') sert=true;
        
        cout<<s[i];
    }
    
    return 0;
}