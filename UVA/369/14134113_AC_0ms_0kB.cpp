// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll dp[105][105];

ll f(int i , int j)
{
    if(i==j)return 1;
    if(j==0)return 1;
    if(j==1)return i;

    if(dp[i][j]!=-1)return dp[i][j];
    return dp[i][j] = f(i-1 , j) + f(i-1 , j-1);
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    memset(dp , -1 , sizeof(dp));

    int n , m;
    while(cin >> n >> m){

        if(n==0&&m==0)break;
        cout << n << " things taken " << m << " at a time is " << f(n , m) << " exactly." << endl;
    }

    return 0;
}
