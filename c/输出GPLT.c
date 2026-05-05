#include <stdio.h>
#include <string.h>
#include <ctype.h>
int main()
{
    char str[10001];
    fgets(str, sizeof(str), stdin);
    int count[4] = {0};
    for (int i = 0; str[i] != '\0'; i++)
    {
        char c = toupper(str[i]);
        if (c == 'G'){
            count[0]++;
        }
        else if (c == 'P'){
            count[1]++;
        }
        else if (c == 'L'){
            count[2]++;
        }
        else if (c == 'T'){
            count[3]++;
        }
    }
      int total = count[0] + count[1] + count[2] + count[3];
    
    while(total > 0) {
        if(count[0] > 0) {
            printf("G");
            count[0]--;
            total--;
        }
        if(count[1] > 0) {
            printf("P");
            count[1]--;
            total--;
        }
        if(count[2] > 0) {
            printf("L");
            count[2]--;
            total--;
        }
        if(count[3] > 0) {
            printf("T");
            count[3]--;
            total--;
        }
    }
return 0;
}