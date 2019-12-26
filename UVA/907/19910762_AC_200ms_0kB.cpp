// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
int dp[605][305] , n , k , v[605];

int f(int i , int rem)
{
    if(i==n)return 0;
    if(rem==0){
        int sum = 0;
        for(int j=i;j<n;j++){
            sum+=v[j];
        }
        return sum;
    }
    if(dp[i][rem]!=-1)return dp[i][rem];
    int value = 1e9 , sum = v[i];
    for(int j=i+1;j<=n;j++){
        value = min(value , max(f(j , rem-1) , sum));
        sum+=v[j];
    }
    return dp[i][rem] = value;
}

int main(void)
{
    while(scanf("%d %d",&n , &k)==2){
        n++;
        for(int i=0;i<n;i++){
            scanf("%d",&v[i]);
        }
        memset(dp , -1 , sizeof(dp));
        printf("%d\n",f(0 , k));
    }
    return 0;
}
