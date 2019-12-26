#include<stdio.h>
int main()
{
    int a , b ,c ,d ,e ,f=0 ,g ,h , mile =0, juice=0;
    scanf("%d",&a);
    for(b=0 ; b<a;b++){
        scanf("%d",&c);
        e=29;f=0 ; mile =0 ; juice =0;
        for(d=0; d<c ;d++){

                scanf("%d",&e);
                for (g=1; ;g++ ){
                    if (((g*30)-1)>=e) {

                        break ;
                    }

                }
                mile = mile + ((g)*10);

                for (g=1; ;g++ ){
                    if (((g*60)-1)>=e) {

                        break ;
                    }

                }
                juice = juice + g*15;

        }
        if (mile<juice) printf("Case %d: Mile %d\n",b+1 ,mile);
        if (mile>juice) printf("Case %d: Juice %d\n",b+1 ,juice);
        if (mile==juice) printf("Case %d: Mile Juice %d\n",b+1 ,mile);
    }
    return 0;
}
