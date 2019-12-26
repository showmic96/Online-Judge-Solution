// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll dp[10005];
int n;
vector<int>v[100005];

ll f(int i)
{
    if(v[i].size()==0)return 1;
    if(dp[i]!=-1)return dp[i];

    ll value = 0;

    for(int j=0;j<v[i].size();j++)value+=f(v[i][j]);

    return dp[i] = value;
}

int main(void)
{
    bool blank = false;
    while(scanf("%d",&n)==1){

        memset(dp  , -1 ,sizeof(dp));

        if(blank)printf("\n");blank = true;

        for(int i=0;i<n;i++){

            int in;
            scanf("%d",&in);
            v[i].clear();

            for(int j=0;j<in;j++){

                int in;
                scanf("%d",&in);
                v[i].push_back(in);
            }
        }

        printf("%lld\n",f(0));
    }
    return 0;
}
