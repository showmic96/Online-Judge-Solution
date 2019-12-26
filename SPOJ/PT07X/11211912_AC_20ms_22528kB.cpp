// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAX = 100000+9;

vector<int>edges[MAX+9];
ll dp[MAX][2];

ll f(int i , int now , int par)
{
    if(dp[i][now]!=-1)return dp[i][now];

    int si = edges[i].size();

    ll value = 0;

    if(now==0){

        value = 1;

        for(int j=0;j<si;j++){

            if(edges[i][j]==par)continue;

            value+=f(edges[i][j] , 1 , i);
        }
    }

    else{

        ll temp = 1;

        for(int j=0;j<si;j++){

            if(edges[i][j]==par)continue;

            temp+=f(edges[i][j] , 1 , i);
        }

        for(int j=0;j<si;j++){

            if(edges[i][j]==par)continue;

            value+=f(edges[i][j] , 0 , i);
        }

        value = min(value , temp);
    }

    return dp[i][now] = value;
}

int main(void)
{
    memset(dp , -1 , sizeof(dp));

    int n;
    scanf("%d",&n);

    for(int i=0;i<n-1;i++){

        int in1 , in2;
        scanf("%d %d",&in1 , &in2);

        edges[in1].push_back(in2);
        edges[in2].push_back(in1);
    }

    ll ans = 1e9;

    for(int i=1;i<=1;i++){

        ans = min(ans , f(i , 0 , -1));
        ans = min(ans , f(i , 1 , -1));
    }

    printf("%lld\n",ans);

    return 0;
}
