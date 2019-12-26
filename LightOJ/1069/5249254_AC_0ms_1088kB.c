#include<stdio.h>
int main(void){
 int a , b , c,d , e ,f;
 scanf("%d",&a);
 for(b=0;b<a;b++){
        e=0;c=0;d=0;f=0;
    scanf("%d %d",&c,&d);
    e=d-c; if(e<0) e=(-1)*e;
    e= e*4;
    d=c*4;
    f=(e+d)+10+9;
    printf("Case %d: %d\n",b+1 ,f);

 }
 return 0;
}