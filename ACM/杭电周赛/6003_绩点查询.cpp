#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    double a,b; cin>>a>>b;

    if(b<45)
    {
        cout<<"0.0"<<endl;
        return;
    }

    double s=ceil(0.6*a+0.4*b);

    double gpa;
    if(s>=95) gpa=5.0;
    else if(s<95&&s>=60) gpa=5-0.1*(95-s);
    else gpa=0;

    printf("%.1lf\n",gpa);
}




int main()
{
    int t; cin>>t;
    while(t--)
    {
        solve();
    }

    return 0;
}