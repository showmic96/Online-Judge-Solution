// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

double dp[505][505];
bool vis[505][505];

double f(int r , int b)
{
    if(b==0&&r==0)return 1.00;

    if(b==0)return 0.00;

    if(r==0)return 1.00;


    if(vis[r][b])return dp[r][b];
    vis[r][b] = true;
    dp[r][b] = 0;

    double value = 0;

    if(b>=2)value += 1.00*b/(b+r)*f(r , b-2);
    if(r>=1)value += 1.00*r/(b+r)*f(r-1 , b-1);

    return dp[r][b] = value;
}

int main(void)
{
    memset(vis , false , sizeof(vis));

    int t , c = 0;
    scanf("%d",&t);

    while(t--){

        int r , b;
        scanf("%d %d",&r , &b);

        printf("Case %d: %.14f\n",++c , f(r , b));
    }
    return 0;
}
