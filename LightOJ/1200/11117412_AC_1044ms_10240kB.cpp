// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int n , w;

vector<int>v1 , v2 , v3;

ll dp[105][10005];

ll f(int i , int w)
{
    if(i==n)return 0;
    if(dp[i][w]!=-1)return dp[i][w];

    ll value = -1e9;

    if(w-v2[i]*v3[i]<0)return dp[i][w] = value;

    value = f(i+1 , w-v2[i]*v3[i]);
    value = max(value , f(i , w-v3[i])+v1[i]);

    return dp[i][w] = value;
}

int main(void)
{
    int t , c = 0;
    scanf("%d",&t);

    while(t--){

        memset(dp , -1 , sizeof(dp));

        scanf("%d %d",&n, &w);

        v1.clear();
        v2.clear();
        v3.clear();

        for(int i=0;i<n;i++){

            int in1 , in2 , in3;
            scanf("%d %d %d",&in1 , &in2 , &in3);

            v1.push_back(in1);
            v2.push_back(in2);
            v3.push_back(in3);
        }

        ll ans = f(0 , w);

        if(ans<0)printf("Case %d: Impossible\n",++c);
        else printf("Case %d: %lld\n",++c , ans);
    }

    return 0;
}
