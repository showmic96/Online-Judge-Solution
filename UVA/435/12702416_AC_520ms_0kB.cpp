// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

int ans[22] , ar[22];

bool Check(int n , int pos)
{
    return n&(1<<pos);
}

int main(void)
{
    int t;
    scanf("%d",&t);
    while(t--){

        int n;
        scanf("%d",&n);

        int total = 0;

        for(int i=0;i<n;i++){

            scanf("%d",&ar[i]);
            total+=ar[i];
        }

        int lim = (1<<n);
        memset(ans , 0 , sizeof(ans));

        for(int i=0;i<=lim;i++){

            int sum = 0;

            for(int j=0;j<n;j++){

                if(Check(i , j)==true){

                    sum+=ar[j];
                }
            }

            for(int j=0;j<n;j++){

                if(Check(i , j)==true){

                    if(sum-ar[j]<=total/2&&sum>total/2){

                        ans[j]++;
                    }
                }
            }
        }

        for(int i=0;i<n;i++){

            printf("party %d has power index %d\n",i+1 , ans[i]);
        }

        printf("\n");
    }
    return 0;
}
