#include <stdio.h>
#include <string.h>
int main()
{
    char a[100];
    fgets(a, sizeof(a), stdin);
    for (int i = 0; a[i] != '\0'; i++)
    {
        if (i == 0)
        {
            if (a[0] == '-')
            {
                printf("fu");
            }
            else if (a[0] == '0')
            {
                printf("ling");
            }
            else if (a[0] == '1')
            {
                printf("yi");
            }
            else if (a[0] == '2')
            {
                printf("er");
            }
            else if (a[0] == '3')
            {
                printf("san");
            }
            else if (a[0] == '4')
            {
                printf("si");
            }
            else if (a[0] == '5')
            {
                printf("wu");
            }
            else if (a[0] == '6')
            {
                printf("liu");
            }
            else if (a[0] == '7')
            {
                printf("qi");
            }
            else if (a[0] == '8')
            {
                printf("ba");
            }
            else if (a[0] == '9')
            {
                printf("jiu");
            }
            continue;
        }
        if (i != 0)
        {
            if (a[i] == '0')
            {
                printf(" ling");
            }
            else if (a[i] == '1')
            {
                printf( " yi");
            }
            else if (a[i] == '2')
            {
                printf(" er");
            }
            else if (a[i] == '3')
            {
                printf(" san");
            }
            else if (a[i] == '4')
            {
                printf(" si");
            }
            else if (a[i] == '5')
            {
                printf(" wu");
            }
            else if (a[i] == '6')
            {
                printf(" liu");
            }
            else if (a[i] == '7')
            {
                printf(" qi");
            }
            else if (a[i] == '8')
            {
                printf(" ba");
            }
            else if (a[i] == '9')
            {
                printf(" jiu");
            }
        }
    }
return 0;
}
