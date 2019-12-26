// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

int dp[1234][1234][3];

int f(int i, int j , int h)
{
    if(i<=0||j<=0)return 0;

    if(dp[i][j][h]!=-1)return dp[i][j][h];

    int value = 0;

    if(h==0){

        value = f(i-5 , j-10 , 1)+1;
        value = max(f(i-20 , j+5 , 2)+1 , value);
    }

    if(h==1){

        value = f(i+3 , j+2 , 0)+1;
        value = max(f(i-20 , j+5 , 2)+1 , value);
    }

    if(h==2){

        value = f(i-5 , j-10 , 1)+1;
        value = max(f(i+3 , j+2 , 0)+1 , value);
    }

    return dp[i][j][h] = value;
}

int main(void)
{
    memset(dp , -1 , sizeof(dp));

    int t;
    scanf("%d",&t);

    while(t--){

        int n , m;
        scanf("%d %d",&n , &m);

        int ans = f(n , m , 0);
        ans = max(ans ,f(n , m , 1));
        ans = max(ans , f(n , m ,2));

        printf("%d\n",ans-1);
    }
    return 0;
}
