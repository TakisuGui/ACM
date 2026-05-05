#include<iostream>
using namespace std;
int main() {
int n,m;
cin>>n>>m;
int a[n];
char name[n][114];
for(int i=0;i<n;i++){
        cin>>a[i]>>name[i];
}
int direction,way,place=0;
for(int p=0;p<m;p++){
    cin>>direction>>way;
    int temp=a[place];
    if((temp==0&&direction==0)||(temp==1&&direction==1)){
        place=(place-way)%n;
        if(place<0){
            place=place+n;
        }
    }
    else if((temp==0&&direction==1)||(temp==1&&direction==0)){
        place=(place+way)%n;
    }
}
printf("%s",name[place]);
return 0;
}