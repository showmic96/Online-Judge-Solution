// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
bool vis[(1<<18)+10][20];
double dp[(1<<18)+10][20] , ar[20][20];
int n;
int Set(int n , int pos)
{
    return n|(1<<pos);
}
bool Check(int n , int pos)
{
    return n&(1<<pos);
}
double f(int mask , int now)
{
    if(mask==(1<<n)-1){
        if(now==0)return 1;
        return 0;
    }
    if(Check(mask , 0)==true&&now!=0)return 0;
    if(vis[mask][now]==true)return dp[mask][now];
    vis[mask][now] = true;
    double value = 0;
    for(int i=0;i<n;i++){
        if(Check(mask , i)==false){
            value = max(value , f(Set(mask , i),i)*ar[i][now] + f(Set(mask , i),now)*ar[now][i]);
        }
    }
    return dp[mask][now] = value;
}
int main(void)
{
    memset(vis , false ,sizeof(vis));
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%lf",&ar[i][j]);
        }
    }
    double ans =0 ;
    for(int i=0;i<n;i++){
        ans=max(ans , f(Set(0 , i) , i));
    }
    printf("%.14f\n",ans);
    return 0;
}
