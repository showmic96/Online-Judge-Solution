// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

string ar;
int dp[55][26];
int si;

int f(int i , int j)
{
    if(j==26)return 0;
    if(i==si)return 26-j;

    if(dp[i][j]!=-1)return dp[i][j];

    int value = 1e9;

    if(ar[i]-'a'==j)value = min(value , f(i+1 , j+1));
    value = min(value , f(i+1 , j+1)+1);
    value = min(value , f(i , j+1)+1);
    value = min(value , f(i+1 , j));

    return dp[i][j] = value;
}

int main(void)
{
    memset(dp , -1 , sizeof(dp));
    cin >> ar;

    si = ar.size();

    cout << f(0 , 0) << endl;
    return 0;
}
