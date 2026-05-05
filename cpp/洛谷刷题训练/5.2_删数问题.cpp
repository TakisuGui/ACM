#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

string s;
int n;

int main()
{
    cin>>s>>n;

    while(n--)
    {
        bool del=false;
        for(int j=0;j<s.size()-1;j++)
        {
            if(s[j]>s[j+1])
            {
                s.erase(j,1);
                del=true;
                break;
            }
        }
        if(!del) s.pop_back();
    }

    while(s.size()>1&&s[0]=='0') s.erase(0,1);

    cout<<s<<endl;

    return 0;
}