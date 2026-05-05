#include<stdio.h>
int main()
{
double m, n;
double x;
scanf("%lf %lf",&m,&n);
 x = ((m-n) / n)*100;
if(m<=n*1.09999){
     printf("OK");
}
else if(n*1.0999<=m&&m<n*1.499999){
    printf("Exceed %.0lf%%. Ticket 200",x);
}
else{
    printf("Exceed %.0lf%%. License Revoked",x);
};
return 0;
}