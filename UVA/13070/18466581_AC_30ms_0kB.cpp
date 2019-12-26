// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<int>v(100005);
int dp[100005][6][2] , n , lim;

int f(int i , int tot , int now)
{
    if(i==n)return 0;
    if(dp[i][tot][now]!=-1)return dp[i][tot][now];
    int value = 0;

    if(now==0){

        value = max(value , f(i+1 , tot , now));
        if(v[i]<lim)value = max(value , f(i+1 , tot , 1)+1);
        else value = max(value , f(i+1 , tot+1 , 1)+1);
    }
    else{

        if(v[i]<lim)value+=f(i+1 , tot , now)+1;
        else if(tot+1<=5)value+=f(i+1 , tot+1 , now)+1;
    }

    return dp[i][tot][now] = value;
}

int main(void)
{
    int t;
    scanf("%d",&t);
    while(t--){

        scanf("%d %d",&lim , &n);
        for(int i=0;i<=n;i++){
            for(int j=0;j<6;j++){
                dp[i][j][0] = -1;
                dp[i][j][1] = -1;
            }
        }
        for(int i=0;i<n;i++){
            scanf("%d",&v[i]);
        }
        printf("%d\n",f(0 , 0 , 0));
    }
    return 0;
}
