#include<stdio.h>
int max(int a,int b,int c){
    if(a>=b&&a>=c){
        return a;
    }
    else if(b>=a&&b>=c){
        return b;
    }
    else if(c>=a&&c>=b){
        return c;
    }
}
int min(int a,int b,int c){
    if(a<=b&&a<=c){
        return a;
    }
    else if(b<=a&&b<=c){
        return b;
    }
    else if(c<=a&&c<=b){
        return c;
    }
}
int mid(int a,int b,int c){
    if ((a >= b && a <= c) || (a >= c && a <= b)) {
        return a;
    } else if ((b >= a && b <= c) || (b >= c && b <= a)) {
        return b;
    } else {
        return c;
    }
}
int main()
{
int n;
int t=1;
scanf("%d",&n);
do{
    int a,b,c;
    a=n/100;
    b=(n-a*100)/10;
    c=n%10;
    int x=max(a,b,c);
    int y=mid(a,b,c);
    int z=min(a,b,c);
    int p=x*100+y*10+z;
    int q=z*100+y*10+x;
    printf("%d: %d - %d = %d\n",t,p,q,p-q);
    n=p-q;
    t++;
}while(n!=495);
return 0;
}