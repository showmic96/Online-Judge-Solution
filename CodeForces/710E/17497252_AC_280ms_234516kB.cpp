// In the name the Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll dp[10000005];
ll n , x , y;

ll f(int n)
{
    if(n==0)return 0;
    if(dp[n]!=-1)return dp[n];
    dp[n] = 1e18;

    ll value = 1e18;

    if(n%2==0){
        value = min(value , f(n/2)+y);
        value = min(value , f(n-1)+x);
    }
    else{

        value = min(value , f((n+1)/2)+x+y);
        value = min(value , f(n-1)+x);
    }
    return dp[n] = value;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    memset(dp , -1 , sizeof(dp));
    cin >> n >> x >> y;

    cout << f(n) << endl;

    return 0;
}
