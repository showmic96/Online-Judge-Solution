// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

int ar[1025][1025];

bool f(int i , int j)
{
    if(i<0||j<0)return false;
    if(i>1024||j>1024)return false;
    return true;
}

int main(void)
{
    int t;
    scanf("%d",&t);
    while(t--){

        memset(ar , 0 , sizeof(ar));

        int d;
        scanf("%d",&d);

        int n;
        scanf("%d",&n);

        for(int i=0;i<n;i++){

            int in1 , in2 , in3;
            scanf("%d %d %d",&in1 , &in2 , &in3);

            int t1 = max(0 , in1-d);
            int t2 = min(1024 , in1+d);
            int t3 = max(0 , in2-d);
            int t4 = min(1024 , in2+d);

            for(int i1=t1;i1<=t2;i1++){

                for(int j1=t3;j1<=t4;j1++){

                    ar[i1][j1]+=in3;
                }
            }
        }

        int mx = 0 , x , y;

        for(int i=0;i<=1024;i++){

            for(int j=0;j<=1024;j++){

                if(ar[i][j]>mx){

                    mx = ar[i][j];
                    x = i;
                    y = j;
                }
            }
        }

        printf("%d %d %d\n",x , y , mx);
    }
    return 0;
}
