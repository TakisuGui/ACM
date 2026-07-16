#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

string s;

int main()
{
    cin>>s;
    ll ans=0;
    stack<char> tp0;
    stack<char> tp1;

    for(char c:s)
    {
        if(c=='A')
        {
            tp0.push(c);
        }
        else if(c=='B')
        {
            if(!tp0.empty())
            {
                tp0.pop();
                tp1.push(c);
            }
        }
        else
        {
            if(!tp1.empty())
            {
                tp1.pop();
                ans++;
            }
        }
    }

    cout<<ans<<endl;

    return 0;
}