#include<stdio.h>
int main()
{
int ch;
char str[1000];
int i=0;
int sign=1;
int found=0;
while((ch=getchar())!='#'){
    if(!found){
        if(ch=='-'){
            sign=-1;
        }
        else if((ch>='0'&&ch<='9')||(ch>='a'&&ch<='f')||(ch>='A'&&ch<='F')){
            found=1;
            str[i]=ch;
            i++;
            
        }
    }
    else 
    {if((ch>='0'&&ch<='9')||(ch>='a'&&ch<='f')||(ch>='A'&&ch<='F')){
        
        str[i]=ch;
        i++;
    }
    else{
        continue;
      }
   }
}
int s=0;
for(int p=0;p<=i-1;p++){
    switch(str[p]){
        case '0':s=s*16+0;
        break;
        case '1':s=s*16+1;
        break;
        case '2':s=s*16+2;
        break;
        case '3':s=s*16+3;
        break;
        case '4':s=s*16+4;
        break;
        case '5':s=s*16+5;
        break;
        case '6':s=s*16+6;
        break;
        case '7':s=s*16+7;
        break;
        case '8':s=s*16+8;
        break;
        case '9':s=s*16+9;
        break;
        case 'A':
        case 'a':s=s*16+10;
        break;
        case 'B':
        case 'b':s=s*16+11;
        break;
        case 'C':
        case 'c':s=s*16+12;
        break;
        case 'D':
        case 'd':s=s*16+13;
        break;
        case 'E':
        case 'e':s=s*16+14;
        break;
        case 'F':
        case 'f':s=s*16+15;
        break;        
    }
}
s=s*sign;
printf("%d",s);
return 0;
}
