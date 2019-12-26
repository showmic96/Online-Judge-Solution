// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll MOD = 1e9 + 7;

int dp[10000000+9][2];
int n;

ll f(int i , int pre)
{
    if(i==0){

        if(pre==1)return 1;
        return 0;
    }

    if(dp[i][pre]!=-1)return dp[i][pre];

    ll value = 0;

    if(pre==1){

        value+=f(i-1 , 2);
        value%=MOD;
        value+=f(i-1 , 2);
        value%=MOD;
        value+=f(i-1 , 2);
        value%=MOD;
    }

    if(pre==2){

        value+=f(i-1 , 1);
        value%=MOD;
        value+=f(i-1 , 2);
        value%=MOD;
        value+=f(i-1 , 2);
        value%=MOD;
    }

    return dp[i][pre] = value ;
}

int main(void)
{
    memset(dp , -1 , sizeof(dp));

    for(int i=1;i<=100;i++)f(i*100000 , 1);

    cin >> n;
    cout << f(n , 1) << endl;

    return 0;
}
