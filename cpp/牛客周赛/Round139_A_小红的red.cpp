#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+10;
const ll INF = 2e18;

int main()
{
    string text; cin>>text;
    bool pass=true;

    for(int i=0;i<text.size();i++)
    {
        if(text[i]!='r'&&text[i]!='e'&&text[i]!='d')
        {
            pass=false;
            break;
        }
    }

    cout<<(pass ? "Yes" : "No")<<endl;

    return 0;
}