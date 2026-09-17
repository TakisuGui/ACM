#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;cin>>n;

    bool hasOutput = false;

    for(int i=n;i>=0;i--)
    {
        //符号
        int a;cin>>a;
        if(a==0)continue;

          hasOutput = true;


        if(a<0)cout<<"-";
        else{
            if(i!=n)cout<<"+";
        }

        //系数
        a=abs(a);
        if(a!=1||(a==1&&i==0))cout<<a;

        //次数
        if(i==0)continue;
        else if(i==1)cout<<'x';
        else cout<<"x^"<<i;


    }

    if(!hasOutput) {
        cout << "0";
    }


    return 0;
}