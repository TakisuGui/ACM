#include<iostream>
#include<algorithm>
using namespace std;
int main(){
string a,b;
cin>>a>>b;
if(a=="0"||b=="0"){
    cout<<"0"<<endl;
    return 0;
}
reverse(a.begin(), a.end());
reverse(b.begin(), b.end());
int len1=a.size();
int len2=b.size();
string res(len1+len2,'0');
for(int i=0;i<len1;i++){
    int carry=0;
    int num1=a[i]-'0';
    for(int j=0;j<len2;j++){
        int num2=b[j]-'0';
        int pos=i+j;
        int sum=(res[pos] - '0') + carry + (num1 * num2);
        res[pos] = (sum % 10) + '0';
        carry = sum / 10;
    }
    if (carry > 0) {
            res[i + len2] = carry + '0';
        }
    }
int idx = len1 + len2 - 1;
    while (idx > 0 && res[idx] == '0') {
        idx--;
    }
 res = res.substr(0, idx + 1);
  reverse(res.begin(), res.end());
    
    cout << res << endl;
    return 0;
}