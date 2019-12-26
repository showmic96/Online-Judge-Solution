// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll dp[100005];

ll f(int n)
{
    if(n==0)return 0;
    if(n==1)return 1;

    if(dp[n]!=-1)return dp[n];

    if(n%2==1)return dp[n] = f(n/2)+f(n-(n/2));
    else return dp[n] = f(n/2);
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int n;
    memset(dp , -1 , sizeof(dp));
    while(cin >> n){

        if(n==0)break;
        ll mx = 0;
        for(int i=1;i<=n;i++)mx = max(mx , f(i));
        cout << mx << endl;
    }

    return 0;
}
