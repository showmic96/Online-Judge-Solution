// In the name of Allah the most Merciful.

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll dp[1010][1010];
ll ar[1010][1010];

ll f(int i , int j)
{
    if(i==0&&j==0)return ar[i][j];
    if(dp[i][j]!=-1)return dp[i][j];

    if(i==0){

        return dp[i][j] = f(i , j-1) + ar[i][j];
    }
    else if(j==0){

        return dp[i][j] = f(i-1 , j) + ar[i][j];
    }

    else{

        return dp[i][j] = min(f(i-1 , j),f(i, j-1)) + ar[i][j];
    }
}

int main(void)
{
    ll n;
    cin >> n;
    memset(dp , -1 , sizeof(dp));

    for(int i=0;i<n;i++){

        for(int j=0;j<n;j++){

            cin >> ar[i][j];
        }
    }

    cout << f(n-1 , n-1) << endl;

    return 0;
}
