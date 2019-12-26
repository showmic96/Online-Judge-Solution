#include<stdio.h>>
int main(void)
{
    int a , b , c;
    while(scanf("%d %d %d",&a,&b,&c)!=EOF){
        if (a==0&&b==0&&c==0) break;
    if ((a*a+b*b)==(c*c)||(a*a+c*c)==(b*b)||(c*c+b*b)==(a*a)) printf("right\n");
    else printf("wrong\n");




    }
    return 0;
}