#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int n,m;

int main()
{
    cin>>n>>m;
    bool pass[m+1]={false};

    while(n--)
    {
        int num; cin>>num;
        int a[num+1];
        for(int i=1;i<=num;i++) cin>>a[i];

        bool find=false;
        for(int i=1;i<=num;i++)
        {
            if(!pass[a[i]])
            {
                cout<<a[i]<<endl;
                pass[a[i]]=true;
                find=true;
                break;
            }
        }

        if(!find) cout<<"0"<<endl;
    }

    return 0;
}