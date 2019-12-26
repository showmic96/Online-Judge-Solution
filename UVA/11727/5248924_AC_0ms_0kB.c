#include<stdio.h>>
int main(void)
{
    long long int a, b , c , d ,t ,x;
    scanf("%llu",&t);
    for(x=0 ;x<t ;x++){
        a=0 ; b=0 ; c=0;
        scanf("%llu %llu %llu",&a,&b,&c);
        if(a>b)
            if (a<c) d=a;
        if(a>c)
            if (a<b) d=a;
        if(b>a)
            if (b<c) d=b;
        if(b>c)
            if (b<a) d=b;
        if(c>b)
            if (c<a) d=c;
        if(c>a)
            if (c<b) d=c;
        printf("Case %llu: %llu\n",x+1 ,d);


  }
    return 0;
}