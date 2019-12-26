// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll dp[5005][5005];
int n , m;
vector<ll>v1 , v2;

ll f(int i , int j)
{
    if(i==n&&j==m)return 0;
    if(j==m)return 1e18;

    if(dp[i][j]!=-1)return dp[i][j];

    ll value = 1e18;

    value = min(value , f(i , j+1));
    value = min(value , f(i+1 , j+1)+abs(v1[i] - v2[j]));

    return dp[i][j] = value;
}

int main(void)
{
    memset(dp , -1 , sizeof(dp));

    scanf("%d %d",&n , &m);
    for(int i=0;i<n;i++){

        ll in;
        scanf("%lld",&in);
        v1.push_back(in);
    }

    for(int i=0;i<m;i++){

        ll in;
        scanf("%lld",&in);
        v2.push_back(in);
    }

    sort(v1.begin() , v1.end());
    sort(v2.begin() , v2.end());

    printf("%lld\n",f(0 , 0));

    return 0;
}
