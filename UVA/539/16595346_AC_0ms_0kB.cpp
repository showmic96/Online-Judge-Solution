// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int n , m , ar[30][30] , counter = 0;

void f(int u , int c)
{
    if(c>counter)counter = c;

    for(int i=0;i<n;i++){

        if(ar[u][i]==1){

            ar[u][i] = 0;
            ar[i][u] = 0;

            f(i , c+1);

            ar[u][i] = 1;
            ar[i][u] = 1;
        }
    }
}

int main(void)
{
    while(scanf("%d %d",&n , &m)==2){

        if(n==0&&m==0)break;

        memset(ar , 0 , sizeof(ar));

        for(int i=0;i<m;i++){

            int in1 , in2;
            scanf("%d %d",&in1 , &in2);
            ar[in1][in2] = 1;
            ar[in2][in1] = 1;
        }

        counter = 0;

        for(int i=0;i<n;i++){

            f(i , 0);
        }
        printf("%d\n",counter);
    }
    return 0;
}
