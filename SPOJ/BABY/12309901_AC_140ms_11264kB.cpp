// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int Set(int n , int pos)
{
    return n|(1<<pos);
}
bool Check(int n , int pos)
{
    return n&(1<<pos);
}

ll dp[17][(1<<16)+5];
int n;
vector<int>v1 , v2;

ll f(int i , int mask)
{
    if(i==n){

        return 0;
    }

    if(dp[i][mask]!=-1)return dp[i][mask];

    ll value = 1e18;

    for(int j=0;j<n;j++){

        if(Check(mask , j)==false){

            value = min(value , f(i+1 , Set(mask , j))+abs(v1[i]-v2[j])+abs(i-j));
        }
    }

    return dp[i][mask] = value;
}

int main(void)
{
    while(scanf("%d",&n)==1){

        if(!n)break;
        memset(dp , -1 , sizeof(dp));

        v1.clear();
        v2.clear();

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

        printf("%lld\n",f(0 , 0));
    }
    return 0;
}
