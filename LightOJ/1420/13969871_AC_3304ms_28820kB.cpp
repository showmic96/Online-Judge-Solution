// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll MOD = 1000000007 , dp[105][105][105][3];
char a[105] , b[105] , c[105];
int si1 , si2 , si3;

ll f(int i , int j , int k , int now)
{
    if(k==si3)return 1;
    if(i==si1&&j==si2)return 0;

    if(dp[i][j][k][now]!=-1)return dp[i][j][k][now];

    ll value = 0;

    if(i<si1&&now!=0){

        if(a[i]==c[k])value+=f(i+1 , j , k+1 , 2);
        value+=f(i+1 , j , k , 1);
    }
    if(j<si2&&now!=1){

        if(b[j]==c[k])value+=f(i , j+1 , k+1 , 2);
        value+=f(i , j+1 , k , 0);
    }

    return dp[i][j][k][now] = value%MOD;
}

int main(void)
{
    int t , tc = 0;
    scanf("%d",&t);
    while(t--){

        memset(dp , -1 , sizeof(dp));
        scanf("%s",&a);
        scanf("%s",&b);
        scanf("%s",&c);

        si1 = strlen(a);
        si2 = strlen(b);
        si3 = strlen(c);

        printf("Case %d: %lld\n",++tc , f(0 , 0 , 0 , 2));
    }
    return 0;
}
