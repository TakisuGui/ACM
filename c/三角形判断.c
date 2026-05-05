#include<stdio.h>
#include<math.h>
int main()
{
double a,b,c,d,e,f;
double l1,l2,l3,L,A;
scanf("%lf %lf %lf %lf %lf %lf",&a,&b,&c,&d,&e,&f);
l1=pow((pow(a-c,2)+pow(b-d,2)),0.5);
l2=pow((pow(a-e,2)+pow(b-f,2)),0.5);
l3=pow((pow(c-e,2)+pow(d-f,2)),0.5);
if(l1==l2+l3){
    printf("Impossible");
}
else if(l2==l1+l3){
    printf("Impossible");
}
else if(l3==l1+l2){
    printf("Impossible");
}
else{
    L=l1+l2+l3;
    A=pow(((0.5*L-l1)*(0.5*L-l2)*(0.5*L-l3)*0.5*L),0.5);
    printf("L = %.2lf, A = %.2lf",L,A);

};
return 0;
}
