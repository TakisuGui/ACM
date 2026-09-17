#include <iostream>
using namespace std;

bool check(int a1,int b1,int a2,int b2){
    if(a1>b1&&a2>b2)return true;
    if(a1==b1&&a2>b2)return true;
    if(a1>b1&&a2==b2)return true;
    return false;
}

int main() {

    int t;scanf("%d",&t);
    int a1,a2,b1,b2;
    while(t--){
        scanf("%d %d %d %d",&a1,&a2,&b1,&b2);
        int cnt=0;
        if(check(a1,b1,a2,b2))cnt++;
        if(check(a1,b2,a2,b1))cnt++;
        if(check(a2,b1,a1,b2))cnt++;
        if(check(a2,b2,a1,b1))cnt++;
        printf("%d\n",cnt);
    }
}
