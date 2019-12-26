// In the name of Allah the Lord of the Worlds.

#include<iostream>
#include<vector>
#include<stdio.h>
#include<queue>
#include<math.h>
#include<algorithm>
#include<set>
using namespace std;

typedef long long ll;
int dp[100005][105] , ar[100005] , n , c;

int f(int i , int last)
{
    if(i==n)return 0;
    if(dp[i][last]!=-1)return dp[i][last];
    int value = 1e9;
    if(i==0){
        for(int j=ar[i];j<=min(100 , ar[i]+12);j++){
            value = min(value , f(i+1 , j)+(abs(ar[i]-j)*(abs(ar[i]-j))));
        }
    }
    else{
        for(int j=ar[i];j<=min(100 , ar[i]+12);j++){
            value = min(value , f(i+1 , j)+(abs(ar[i]-j)*abs(ar[i]-j))+(c*abs(j-last)));
        }
    }
    return dp[i][last] = value;
}

int main(void)
{
    scanf("%d %d",&n , &c);
    for(int i=0;i<n;i++)scanf("%d",&ar[i]);
    for(int i=0;i<=100000;i++){
        for(int j=0;j<=100;j++){
            dp[i][j] = -1;
        }
    }
    printf("%d\n",f(0 , 0));
    return 0;
}
