// In the name the Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int dp[305][305][2];

int f(int i , int j , int k)
{
    if(i==0&&j==0){
        if(k==0)return 1;
        return 0;
    }
    if(dp[i][j][k]!=-1)return dp[i][j][k];

    int value = k^1;
    int mi = min(i , j);
    for(int l=1;l<=mi;l++){
        if(k==0)value = min(value , f(i-l , j-l , k^1));
        else value = max(value , f(i-l , j-l , k^1));
    }
    for(int l=1;l<=i;l++){
        if(k==0)value = min(value , f(i-l , j , k^1));
        else value = max(value , f(i-l , j , k^1));
    }
    for(int l=1;l<=j;l++){
        if(k==0)value = min(value , f(i , j-l , k^1));
        else value = max(value , f(i , j-l , k^1));
    }

    return dp[i][j][k] = value;
}

int main(void)
{
    int n;
    scanf("%d",&n);
    vector<int>v(n);
    for(int i=0;i<n;i++)scanf("%d",&v[i]);
    if(n==1&&v[0]!=0)printf("BitLGM\n");
    else if(n==1)printf("BitAryo\n");
    else if(n==2){
        memset(dp , -1 , sizeof(dp));
        int ans = f(v[0] , v[1] , 0);
        if(ans==0)printf("BitLGM\n");
        else printf("BitAryo\n");
    }
    else{
        int ans = v[0]^v[1]^v[2];
        if(ans!=0)printf("BitLGM\n");
        else printf("BitAryo\n");
    }
    return 0;
}
