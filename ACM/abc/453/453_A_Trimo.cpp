#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    int n; cin>>n;
    string text; cin>>text;
    
    int pos=0;
    while(pos<n&&text[pos]=='o') pos++;

    if(pos==n) cout<<"";
    else for(int i=pos;i<n;i++) cout<<text[i];
    cout<<endl;

    return 0;
}