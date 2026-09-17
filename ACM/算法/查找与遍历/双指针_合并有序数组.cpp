#include<bits/stdc++.h>
using namespace std;

int m,n;

void merge(vector<int>& num1,int m,vector<int>& num2,int n){

    int index=m+n-1;

    int i=m-1;int j=n-1;

    while(i>=0&&j>=0){
        if(num1[i]>=num2[j]){
            num1[index--]=num1[i--];

        }
        else{
            num1[index--]=num2[j--];
        }
    }

    while(j>=0){
        num1[index--]=num2[j--];
    }

}




int main(){
    cin>>m>>n;

    vector<int> num1(m+n);vector<int> num2(n);

    for(int i=0;i<m;i++)cin>>num1[i];
    for(int j=0;j<n;j++)cin>>num2[j];

    merge(num1,m,num2,n);

    for(int i=0;i<m+n;i++){
        cout<<num1[i]<<" ";
    }


    return 0;
}