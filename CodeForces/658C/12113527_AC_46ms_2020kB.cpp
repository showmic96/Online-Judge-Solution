// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(void)
{
    int n , d , h;
    scanf("%d %d %d",&n , &d , &h);

    if(n<max(d,h))printf("-1\n");
    else if(h>d)printf("-1\n");
    else if(d>2*h)printf("-1\n");
    else{

        if(h==d){

            if(h==1&&n!=2){

                printf("-1\n");
                return 0;
            }
        }

        int counter = 2;
        n--;

        if(d==h){

            for(int i=0;i<d;i++){

                printf("%d %d\n",counter-1 , counter);
                counter++;
                n--;
            }

            while(n!=0){

                printf("2 %d\n",counter);
                counter++;
                n--;
            }
        }

        else{

            for(int i=0;i<h;i++){

                printf("%d %d\n",counter-1 , counter);
                counter++;
                n--;
            }

            for(int i=0;i<d-h;i++){

                if(i==0){

                    printf("1 %d\n",counter);
                    counter++;
                    n--;
                }
                else{

                    printf("%d %d\n",counter-1 , counter);
                    counter++;
                    n--;
                }
            }

            while(n!=0){

                printf("1 %d\n",counter);
                counter++;
                n--;
            }
        }
    }

    return 0;
}
