// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll MOD = 100000007;

int n , k;
ll ar[111] , br[111];
ll dp[111][1111];

ll f(int i , int value)
{
    if(i==n){

        if(value==k)return 1;
        else return 0;
    }

    if(dp[i][value]!=-1)return dp[i][value];

    ll temp = 0;

    for(int j=0;j<=br[i];j++){

        if(value + ar[i]*j > k)break;
        temp+= f(i+1 , value + ar[i]*j);
        temp%=MOD;
    }

    return dp[i][value] = temp;
}

int main(void)
{
    int t;
    cin >> t;
    for(int i=0;i<t;i++){

        memset(dp , -1 , sizeof(dp));

        cin >> n >> k;
        //n*=2;

        for(int i=0;i<n;i++)cin >> ar[i];
        for(int i=0;i<n;i++)cin >> br[i];

        printf("Case %d: %lld\n",i+1 , f(0 , 0));
    }

    return 0;
}
