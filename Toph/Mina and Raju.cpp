// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll dp[205][105][105];
int n , m , p , q , t;
ll MOD = 1000000007;
ll f(int i , int tot , int b)
{
    if(i==n+m+1){

        if(tot==t){

            if(b>=p&&tot-b>=q)return 1;
        }
        return 0;
    }
    if(dp[i][tot][b]!=-1)return dp[i][tot][b];

    ll value = 0;
    if(tot==t)value+=f(i+1 , tot , b);
    else{

        if(i<=n)value+=f(i+1 , tot+1 , b+1);
        else value+=f(i+1 , tot+1 , b);
        value+=f(i+1 , tot , b);

        value%=MOD;
    }
    return dp[i][tot][b] = value%MOD;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int tc;
    cin >> tc;
    while(tc--){

        cin >> n >> m >> p >> q >> t;
        memset(dp , -1 , sizeof(dp));
        cout << f(1 , 0 , 0) << endl;
    }

    return 0;
}