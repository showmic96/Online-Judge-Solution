// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

int ar[55];

int main(void)
{
    int a[3] , b[2];
    while(scanf("%d %d %d %d %d",&a[0] , &a[1] ,&a[2],&b[0],&b[1])==5){

        if(a[0]==0)break;

        sort(a, a+3);
        sort(b, b+1);

        memset(ar , 0 , sizeof(ar));

        for(int i=0;i<3;i++){

            ar[a[i]]=1;
        }
        ar[b[0]] = 1;
        ar[b[1]] = 1;

        int counter = 0;

        for(int i=1;i>=0;i--){

            for(int j=0;j<3;j++){

                if(b[i]<a[j]){

                    a[j] = -1;
                    counter++;
                    break;
                }
            }
        }

        if(counter==2)printf("-1\n");
        else if(counter==0){

            for(int i=1;i<=55;i++){

                if(ar[i]==0){

                    printf("%d\n",i);
                    break;
                }
            }
        }
        else{

            int x;
            for(int i=0;i<3;i++){

                if(a[i]!=-1)x=a[i];
            }

            for(int i=x;i<=55;i++){

                if(ar[i]==0){
                    
                    if(i>52)printf("-1\n");
                    else printf("%d\n",i);
                    break;
                }
            }
        }

    }
    return 0;
}
