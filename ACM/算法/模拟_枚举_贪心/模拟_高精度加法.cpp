#include<iostream>
#include<algorithm>
using namespace std;
int main(){
string a,b,res;
cin>>a>>b;
int i=a.size()-1,j=b.size()-1;
int carry=0;
while(i>=0||j>=0||carry!=0){
    int sum=carry;
    if(i>=0){
        sum=sum+(a[i--]-'0');
    }
    if(j>=0){
        sum=sum+(b[j--]-'0');
    }
    char temp=(sum%10)+'0';
    res.push_back(temp);
    carry=sum/10;
}
reverse(res.begin(),res.end());
cout<<res<<endl;
return 0;
}