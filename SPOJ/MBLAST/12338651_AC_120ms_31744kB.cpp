// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

int n , m , k;
string ar , br;

int dp[2005][2005];

int f(int i , int j)
{
    if(i>n)return 1e7;
    if(j>m)return 1e7;
    if(i==n&&j==m)return 0;

    if(dp[i][j]!=-1)return dp[i][j];

    int value = 1e7;

    value = min(value , f(i+1 , j)+k);
    value = min(value , f(i , j+1)+k);
    value = min(value , f(i+1, j+1)+abs(ar[i]-br[j]));

    return dp[i][j] = value;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    memset(dp , -1 , sizeof(dp));

    cin >> ar >> br >> k;

    n = ar.size();
    m = br.size();

    cout << f(0 , 0) << endl;

    return 0;
}
