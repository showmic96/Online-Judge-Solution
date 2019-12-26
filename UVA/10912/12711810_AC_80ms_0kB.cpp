// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

int dp[27][27][352];
int n , s , c = 0;

int f(int i , int l , int sum)
{
    if(i==26){

        if(l==n&&sum==s)return 1;
        return 0;
    }

    if(sum>s||l>n)return 0;

    if(dp[i][l][sum]!=-1)return dp[i][l][sum];

    int value = 0;

    value+=f(i+1 , l , sum);
    value+=f(i+1 , l+1 , sum+i+1);

    return dp[i][l][sum] = value;
}

int main(void)
{
    while(scanf("%d %d",&n , &s)==2){

        if(!n&&!s)break;
        if(n>26||s>351){

            printf("Case %d: 0\n",++c);
        }

        else{

            memset(dp , -1 , sizeof(dp));
            printf("Case %d: %d\n",++c , f(0 , 0 , 0));
        }
    }

    return 0;
}
