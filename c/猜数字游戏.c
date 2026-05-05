#include<stdio.h>
int main()
{
int a,b,n,c=0;
int guess;
scanf("%d %d",&a,&n);
for(b=1;b<=n;b++){
    scanf("%d",&guess);
    if(guess<0){
        break;
    }
    else if(guess<a){
        printf("Too small\n");
        c=c+1;
    }
    else if(guess>a){
        printf("Too big\n");
        c=c+1;
    }   
    else{
        c=c+1;
        break;
    };
};
if(b>n||guess<0){
    printf("Game Over");
    return 0;
}
else if(b<=n){
    if(c==1){
        printf("Bingo!");
    }
    else if(1<c&&c<=3){
        printf("Lucky You!");
    }
    else{
        printf("Good Guess!");
    };
};
return 0;
}

