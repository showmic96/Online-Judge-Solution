#include<stdio.h>>

int main(void)
{
    long long int a , b , c;
    while(scanf("%lld %lld",&a,&b)!=EOF){
        c=a*b-1;
        printf("%lld\n",c);
    }
    return 0;
}