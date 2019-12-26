// In the name of Allah the Lord of the Worlds.

#include<stdio.h>
#include<math.h>
typedef long long ll;

ll dp[105][105];
ll ar[105][105];
int n , m;

ll max(ll a , ll b)
{
    if(a>b)return a;
    return b;
}

ll f(int i , int j)
{
    if(i>=n||j>=m)return -1e18;
    if(j<0)return -1e18;

    if(dp[i][j]!=-1)return dp[i][j];

    if(i==n-1)return ar[i][j];

    ll value = -1e18;

    value = max(value , f(i+1 , j)+ar[i][j]);
    value = max(value , f(i+1 , j+1)+ar[i][j]);
    value = max(value , f(i+1 , j-1)+ar[i][j]);

    return dp[i][j] = value;
}

int main(void)
{
    int t;
    scanf("%d",&t);
    while(t--){

        for(int i=0;i<105;i++){

            for(int j=0;j<105;j++)dp[i][j] = -1;
        }

        scanf("%d %d",&n , &m);

        for(int i=0;i<n;i++){

            for(int j=0;j<m;j++){

                scanf("%lld",&ar[i][j]);
            }
        }

        ll ans = 0;

        for(int i=0;i<m;i++){

            ans = max(ans , f(0 , i));
        }

        printf("%lld\n",ans);
    }
    return 0;
}
