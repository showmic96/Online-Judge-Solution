// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
int dp[1005][1005];
vector<int>v;

int f(int i , int last)
{
    if(i==v.size()){
        return 0;
    }
    if(dp[i][last]!=-1)return dp[i][last];
    int value = f(i+1 , last);
    if(last==1003){
        value = max(value , f(i+1 , i)+1);
    }
    else{
        if(v[i]<=v[last])value = max(value , f(i+1 , i)+1);
    }
    return dp[i][last] = value;
}

int main(void)
{
    int in , c = 0;
    bool blank = false;
    while(scanf("%d",&in)==1){
        if(in==-1)break;
        if(blank==true)printf("\n");blank = true;
        v.clear();
        v.push_back(in);
        while(scanf("%d",&in)){
            if(in==-1)break;
            v.push_back(in);
        }
        memset(dp , -1 , sizeof(dp));
        printf("Test #%d:\n",++c);
        printf("  maximum possible interceptions: %d\n",f(0 , 1003));
    }
    return 0;
}
