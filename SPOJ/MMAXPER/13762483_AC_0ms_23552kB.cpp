// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll dp[1005][1005];
vector<int>v1 , v2;
int n;

ll f(int i , int last)
{
    if(i==n)return 0;
    if(dp[i][last]!=-1)return dp[i][last];

    ll value = f(i+1 , v1[i])+v2[i]+abs(last-v1[i]);
    value = max(value , f(i+1 , v2[i])+v1[i]+abs(last-v2[i]));

    return dp[i][last] = value;
}

int main(void)
{
    scanf("%d",&n);
    memset(dp , -1 , sizeof(dp));

    for(int i=0;i<n;i++){

        int in1 , in2;
        scanf("%d %d",&in1, &in2);

        v1.push_back(in1);
        v2.push_back(in2);
    }

    printf("%lld\n",max(f(1 , v1[0])+v2[0] , f(1 , v2[0])+v1[0]));

    return 0;
}
