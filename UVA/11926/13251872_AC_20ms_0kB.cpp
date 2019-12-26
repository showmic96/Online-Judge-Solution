// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

int ar[2000005];

int main(void)
{
    int n , m;
    while(scanf("%d %d",&n , &m)==2){

        if(!n&&!m)break;
        memset(ar ,0 , sizeof(ar));
        for(int i=0;i<n;i++){

            int in1 , in2;
            scanf("%d %d",&in1 , &in2);
            ar[in1]++;
            ar[in2]--;
        }

        for(int i=0;i<m;i++){

            int in1 , in2 , in3;
            scanf("%d %d %d",&in1 , &in2 , &in3);

            for(int j=0;;j++){

                int temp = j*in3;
                if(temp>1000000)break;

                ar[temp+in1]++;
                ar[temp+in2]--;
            }
        }

        bool check = true;
        if(ar[0]>1)check = false;
        for(int i=1;i<=1000000;i++){

            ar[i] = ar[i]+ar[i-1];
            if(ar[i]>1){
                check = false;
                break;
            }
        }

        if(check)printf("NO CONFLICT\n");
        else printf("CONFLICT\n");
    }
    return 0;
}
