// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

const int MAX = 1000+5;
int dp[MAX][MAX][3];
vector<int>v1 , v2;

int f(int i , int j , int now)
{
    if(i==v1.size()||j==v2.size())return 0;
    if(dp[i][j][now]!=-1)return dp[i][j][now];
    if(now==0){
        int value = f(i+1 , j , now);
        value = max(value , f(i , j , 2));
        return dp[i][j][now] = value;
    }
    else if(now==1){
        int value = f(i+1 , j , now);
        if(v1[i]>v2[j])value = max(value , f(i , j+1 , 2));
        return dp[i][j][now] = value;
    }
    else{
        int value = f(i , j+1 , now);
        if(v1[i]==v2[j])value=  max(value , f(i+1 , j , 1)+1);
        return dp[i][j][now] = value;
    }
}

int main(void)
{
    int t;
    scanf("%d",&t);
    while(t--){
        v1.clear();
        v2.clear();
        int n , m;
        scanf("%d",&n);
        for(int i=0;i<n;i++){
            int in;
            scanf("%d",&in);
            v1.push_back(in);
        }
        scanf("%d",&m);
        for(int i=0;i<m;i++){
            int in;
            scanf("%d",&in);
            v2.push_back(in);
        }
        memset(dp , -1 , sizeof(dp));
        printf("%d\n",f(0 , 0 , 0));
    }
    return 0;
}
