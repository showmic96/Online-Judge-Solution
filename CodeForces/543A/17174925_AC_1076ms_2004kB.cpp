// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll dp[505][505];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    ll n , m , b , mod;
    cin >> n >> m >> b >> mod;

    memset(dp , 0 , sizeof(dp));
    dp[0][0] = 1;

    vector<ll>v(n);
    for(int i=0;i<n;i++){

        cin >> v[i];
    }

    for(int k=0;k<n;k++){

        for(int i=0;i<=m-1;i++){

            for(int j=0;j<=b;j++){

                if(j+v[k]>b)continue;
                dp[i+1][j+v[k]]+=dp[i][j];
                dp[i+1][j+v[k]]%=mod;
            }
        }
    }

    ll sum = 0;

    for(int i=0;i<=b;i++){
        sum+=dp[m][i];
        sum%=mod;
    }

    cout << sum << endl;

    return 0;
}
