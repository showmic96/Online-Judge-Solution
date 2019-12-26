// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
ll MOD = 998244353;

ll dp[1005][2005][2][2];
int n , k;

ll f(int i , int c , int s , int e)
{
    if(i==n){

        if(c==k)return 1;
        return 0;
    }
    if(dp[i][c][s][e]!=-1)return dp[i][c][s][e];

    ll value = 0;

    if(s==1&&e==1){

        value+=f(i+1 , c , 1 , 1);
        value+=f(i+1 , c+1 , 1 , 0);
        value+=f(i+1 , c+1 , 0 , 1);
        value+=f(i+1 , c+1 , 0 , 0);
    }
    if(s==0&&e==0){

        value+=f(i+1 , c+1 , 1 , 1);
        value+=f(i+1 , c+1 , 1 , 0);
        value+=f(i+1 , c+1 , 0 , 1);
        value+=f(i+1 , c , 0 , 0);
    }
    if(s==1&&e==0){

        value+=f(i+1 , c , 1 , 1);
        value+=f(i+1 , c , 1 , 0);
        value+=f(i+1 , c+2 , 0 , 1);
        value+=f(i+1 , c , 0 , 0);
    }
    if(s==0&&e==1){

        value+=f(i+1 , c , 1 , 1);
        value+=f(i+1 , c+2 , 1 , 0);
        value+=f(i+1 , c , 0 , 1);
        value+=f(i+1 , c , 0 , 0);
    }

    return dp[i][c][s][e] = value%MOD;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> n >> k;

    memset(dp , -1 , sizeof(dp));

    cout << (f(1 , 1 , 1 , 1) + f(1 , 1 , 0 , 0) + f(1 , 2 , 1 , 0)
            + f(1 , 2 , 0 , 1))%MOD << endl;

    return 0;
}
