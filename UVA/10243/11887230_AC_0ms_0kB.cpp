// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAX = 1e3 + 9;

vector<int>edges[MAX+9];

ll dp[MAX+9][2];

ll f(int i , int p , int now)
{
    if(dp[i][now]!=-1)return dp[i][now];

    int si = edges[i].size();

    ll value = 0;
    if(now==0)value++;

    for(int j=0;j<si;j++){

        if(now==0){

            if(edges[i][j]!=p)value+=f(edges[i][j] , i , 1);
        }

        else{

            if(edges[i][j]!=p)value+=f(edges[i][j] , i , 0);
        }
    }

    if(now==1){

        ll v = 1;

        for(int j=0;j<si;j++){

            if(edges[i][j]!=p)v+=f(edges[i][j] , i , 1);
        }

        value = min(value , v);
    }

    return dp[i][now] = value;
}

int main(void)
{
    int n;
    while(scanf("%d",&n)==1){

        if(n==0)break;

        memset(dp , -1 , sizeof(dp));

        for(int i=1;i<=n;i++){

            edges[i].clear();

            int si;
            scanf("%d",&si);
            for(int j=0;j<si;j++){

                int in;
                scanf("%d",&in);
                edges[i].push_back(in);
                //edges[in].push_back(i);
            }
        }

        ll ans = 0;

        ans=min(f(1 , 0 , 0) , f(1 , 0, 1));


        ans = max(ans , 1LL);

        printf("%lld\n",ans);
    }

    return 0;
}
