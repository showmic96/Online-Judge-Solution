// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAX = 105;
int dp[105][100005];
vector<int>v1 , v2 , v;
int n , k;

int f(int i , int tot)
{
    if(i==n){
        if(tot==0)return 0;
        return -1e7;
    }
    if(dp[i][tot]!=-1)return dp[i][tot];
    int value = f(i+1 , tot);
    value = max(value , f(i+1 , tot+v[i])+v1[i]);
    return dp[i][tot] = value;
}

int main(void)
{
    scanf("%d %d",&n , &k);
    for(int i=0;i<n;i++){
        int in;
        scanf("%d",&in);
        v1.push_back(in);
    }
    for(int i=0;i<n;i++){
        int in;
        scanf("%d",&in);
        v2.push_back(in);
    }
    for(int i=0;i<n;i++){
        v.push_back(v1[i]-v2[i]*k);
    }
    memset(dp , -1 , sizeof(dp));
    int ans = f(0 , 0);
    if(ans<=0)ans = -1;
    printf("%d\n",ans);
    return 0;
}
