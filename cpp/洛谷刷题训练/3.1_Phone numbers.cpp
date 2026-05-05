#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int n;
string text;

int main()
{
    cin>>n>>text;

    text=' '+text;

    if(n%2==0)
    {
        for(int i=1;i<=n;i++)
        {
            if(i==1)
            {
                cout<<text[i];
                continue;
            }

            if(i%2==1)
            {
                cout<<"-"<<text[i];
            }
            else cout<<text[i];
        }
    }
    else
    {
        for(int i=1;i<=n;i++)
        {
            if(i==2)
            {
                cout<<text[i];
                continue;
            }

            if(i%2==0)
            {
                cout<<"-"<<text[i];
            }
            else cout<<text[i];
        }
    }

    return 0;
}