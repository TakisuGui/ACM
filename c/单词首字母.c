#include<stdio.h>
int main()
{
    char ch;
    int new_word = 1;  // 添加标志：1表示新单词开始
    
    while(1){
        ch = getchar();
        if(ch == '\n'){
            break;
        }
        
        if(new_word && ch >= 'a' && ch <= 'z'){
            // 新单词开始且是小写字母，转为大写
            putchar(ch - 32);
            new_word = 0;  // 重置标志
        }
        else if(ch == ' '){
            putchar(ch);
            new_word = 1;  // 空格后下一个字符可能是新单词开始
        }
        else{
            putchar(ch);
            new_word = 0;  // 普通字符，不是新单词开始
        }
    }
    return 0;
}