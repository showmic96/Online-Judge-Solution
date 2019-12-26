// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll n , k;

double dp[3005][3005];

double f(int i , int sum)
{
    if(i==0){

        if(sum==0)return 1;
        return 0;
    }

    if(dp[i][sum]!=-1)return dp[i][sum];

    double value = 0;

    value+=f(i-1 , sum-1)/6.00;
    value+=f(i-1 , sum-2)/6.00;
    value+=f(i-1 , sum-3)/6.00;
    value+=f(i-1 , sum-4)/6.00;
    value+=f(i-1 , sum-5)/6.00;
    value+=f(i-1 , sum-6)/6.00;

    return dp[i][sum] = value;
}

int main(void)
{
    int t;
    scanf("%d",&t);

    for(int i=0;i<3005;i++){

        for(int j=0;j<3005;j++){

            dp[i][j] = -1;
        }
    }

    while(t--){

        scanf("%lld %lld",&n , &k);

        if(n>3000||k>3000)printf("0\n");
        else{

            printf("%lld\n",(ll)(f(n , k)*100));
        }
    }
    return 0;
}
