#include<stdio.h>

int main (void)
{
    long int a ,f=0;
    long int b , c=0,d=0,e=1;


    while (scanf("%ld",&a)!=EOF)
    { f=0; d=1;
        if (a<0) break ;
        for (b=0 ; d<a ;b++){
                d = (d*2);
                d+=f;

        }
        

      printf("Case %ld: %ld\n",e ,b);
    e=e+1;
    }


    return 0;
}