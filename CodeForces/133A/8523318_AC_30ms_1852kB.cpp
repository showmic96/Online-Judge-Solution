#include<stdio.h>
#include<string.h>
int main()
{
    char ch[111];

    scanf("%s",&ch);

    int si = strlen(ch) , i = 0;

    for(i=0;i<si;i++){

        if(ch[i]=='H'||ch[i]=='Q'||ch[i]=='9'){
            printf("YES");
            return 0;
        }
    }

    printf("NO");
    return 0;
}
