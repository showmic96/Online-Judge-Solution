// In the name of Allah the Most Merciful.

#include<iostream>
#include<stdio.h>
#include<algorithm>;
#include<string>

using namespace std;

typedef long long ll;

char ar[2005] , in[10];
pair<ll , ll > cost[26];
int n , m;
ll dp[2005][2005];

ll f(int i , int j)
{
    if(i>=j)return 0;
    if(dp[i][j]!=-1)return dp[i][j];
    ll value = 1e15;
    if(ar[i]==ar[j]){
        value = min(value , f(i+1 , j-1));
        value = min(value , f(i+1 , j)+cost[ar[i]-'a'].second);
        value = min(value , f(i , j-1)+cost[ar[j]-'a'].second);
        value = min(value , f(i , j-1)+cost[ar[j]-'a'].first);
        value = min(value , f(i+1 , j)+cost[ar[i]-'a'].first);
    }
    else{
        value = min(value , f(i+1 , j)+cost[ar[i]-'a'].second);
        value = min(value , f(i , j-1)+cost[ar[j]-'a'].second);
        value = min(value , f(i , j-1)+cost[ar[j]-'a'].first);
        value = min(value , f(i+1 , j)+cost[ar[i]-'a'].first);
    }
    return dp[i][j] = value;
}

int main(void)
{
    scanf("%d %d",&n , &m);
    scanf("%s",&ar);
    for(int i=0;i<n;i++){
        scanf("%s",&in);
        ll in1 , in2;
        scanf("%lld %lld",&in1 , &in2);
        cost[in[0]-'a'] = make_pair(in1 , in2);
    }
    for(int i=0;i<=m;i++){
        for(int j=0;j<=m;j++){
            dp[i][j] = -1;
        }
    }
    printf("%lld\n",f(0 , m-1));
    return 0;
}
