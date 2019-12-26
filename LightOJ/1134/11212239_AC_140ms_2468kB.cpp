// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
ll dp[100005];

int main(void)
{
    int t , c = 0;
    scanf("%d",&t);

    while(t--){

        memset(dp , 0 , sizeof(dp));

        int n , m;
        scanf("%d %d",&n , &m);

        int sum = 0;
        ll ans = 0;
        dp[0] = 1;

        for(int i=0;i<n;i++){

            int in;
            scanf("%d",&in);
            sum+=in;
            sum%=m;

            ans+=dp[sum];
            dp[sum]++;
        }

        printf("Case %d: %lld\n",++c , ans);
    }

    return 0;
}
