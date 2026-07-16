#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

string s;

int main()
{
    cin>>s;
    s[0]=s[0]+'a'-'A';

    s=string("Of")+s;

    cout<<s<<endl;
    return 0;
}