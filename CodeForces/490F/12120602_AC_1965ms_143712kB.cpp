// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

int dp[6005][6005];

vector<int>edges[6005];
vector<int>v;

int f(int i , int mx , int p)
{
    if(dp[i][mx]!=-1)return dp[i][mx];
    dp[i][mx] = 0;
    int value = 0 , si = edges[i].size();

    for(int j=0;j<si;j++){

        if(p==edges[i][j])continue;

        value = max(value , f(edges[i][j] , mx , i));
    }

    if(v[i]>v[mx]){

        int m = 1;

        for(int j=0;j<si;j++){

            if(p==edges[i][j])continue;

            m = max(m , f(edges[i][j] , i , i)+1);
        }

        value = max(m , value);
    }

    return dp[i][mx] = value;
}

int main(void)
{
    memset(dp , -1 , sizeof(dp));
    v.push_back(0);

    int n;
    scanf("%d",&n);

    for(int i=0;i<n;i++){

        int in;
        scanf("%d",&in);
        v.push_back(in);
    }

    for(int i=0;i<n-1;i++){

        int in1 , in2;
        scanf("%d %d",&in1, &in2);

        edges[in1].push_back(in2);
        edges[in2].push_back(in1);
    }

    int ans = 0;

    for(int i=1;i<=n;i++){

        ans = max(ans , f(i , i , i));
    }

    printf("%d\n",ans+1);

    return 0;
}
