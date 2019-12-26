// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int dp[10005][(1<<10)+5] , MOD = 1e9+7;
int n;
string ar;

bool Check(int mask , int pos)
{
    return mask&(1<<pos);
}

int Set(int mask , int pos)
{
    return mask|(1<<pos);
}

ll f(int i , int mask)
{
    if(i==n)return 1;
    if(dp[i][mask]!=-1)return dp[i][mask];

    ll value = 0;

    if(Check(mask , ar[i]-'0')==false){

        value+=f(i+1 , Set(mask , ar[i]-'0'));
        value%=MOD;
    }

    if(mask!=0)value+=f(i+1 , Set(0 , ar[i]-'0'));

    value%=MOD;

    return dp[i][mask] =  value;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    memset(dp , -1 , sizeof(dp));

    cin >> n;
    cin >> ar;

    cout << f(0 , 0) << endl;

    return 0;
}
