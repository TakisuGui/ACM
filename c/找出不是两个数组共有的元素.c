#include<stdio.h>
int main()
{
int m,n,a,b,c,d,e;
e =0;
scanf("%d",&m);
int p[m];
for(a=0;a<m;a++){
    scanf("%d",&p[a]);
}
scanf("%d",&n);
int q[n];
for(b=0;b<n;b++){
    scanf("%d",&q[b]);
}
int found,ans;
int first =1;
for(a=0;a<m;a++){
    found = 0;
    for(b=0;b<n;b++){
        if (p[a]==q[b]){
            found = 1;
            break;
        }
    }
    if(!found){
        ans=0;
        for(int k=0;k<a;k++){
            if(p[a]==p[k]){
                ans = 1 ;
                break;
            }
        }  
        if(!ans){
            if(!first){
                printf(" ");}
            printf("%d",p[a]);
            first = 0;
            e = e +1;
        }
    }
}
first = 1;
for(b=0;b<n;b++){
    found = 0;
    for(a=0;a<m;a++){
        if (p[a]==q[b]){
            found = 1;
            break;
        }
    }
    if(!found){
        ans=0;
        for(int k=0;k<b;k++){
            if(q[b]==q[k]){
                ans = 1 ;
                break;
            }
        }  
        if(!ans){
           if(!first||e!=0){
                printf(" ");}
            printf("%d",q[b]);
            first = 0;
            e=1;
        }
    }
}
return 0;
}