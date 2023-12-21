#include <stdio.h>

int lengthOfLongestSubstring(char* s) {
    int n=0, i=0, j;
    char a=*s, b;
    while (a!='\0') {
        j=1;
        b=*(s+i+j);
        while(a != b) {
            if (b == '\0')break;
        j++;
        b=*(s+i+j);
        }        
        if(j>n) n=j;
        i++;
        a = *(s + i);
        printf("%d\n", n);
    }
    return n;
}

void main()
{
    char str[100] = "abcabcbb";
    printf("%d", lengthOfLongestSubstring(str));
}
