// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll MOD = 1000000;
int n , k;

ll dp[222][222];

ll f(int i , ll value)
{
    if(i==n){

        if(value==k)return 1;
        return 0;
    }

    if(dp[i][value]!=-1)return dp[i][value];

    ll sum = 0;

    for(int j=0;j<=k;j++){

        if(value+j<=k){

            sum+=f(i+1 , value+j);
            sum%=MOD;
        }

        else break;
    }

    return dp[i][value] = sum;
}
int main(void)
{
    while(cin >> k >> n){

        if(!k&&!n)break;

        memset(dp , -1 , sizeof(dp));

        cout << f(0 , 0) << endl;
    }
    return 0;
}
