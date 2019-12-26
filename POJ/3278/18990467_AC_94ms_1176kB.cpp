// In the name of Allah the Lord of the Worlds.

#include<iostream>
#include<vector>
#include<stdio.h>
#include<queue>
using namespace std;

typedef long long ll;
int dp[200005] , n , x;

int f()
{
    queue<int>current;
    current.push(n);
    dp[n] = 0;
    while(!current.empty()){
        int u = current.front();
        current.pop();
        if(u==x)return dp[x];
        if(u+1<200000&&dp[u+1]==-1){
            current.push(u+1);
            dp[u+1]=dp[u]+1;
        }
        if(u-1>=0&&dp[u-1]==-1){
            current.push(u-1);
            dp[u-1] = dp[u]+1;
        }
        if(u*2<200000&&dp[u*2]==-1){
            current.push(u*2);
            dp[u*2] = dp[u]+1;
        }
    }
}

int main(void)
{
    scanf("%d %d",&n , &x);
    for(int i=0;i<=100000;i++)dp[i] = -1;
    printf("%d\n",f());
    return 0;
}
