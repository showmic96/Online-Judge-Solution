// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

int dp[12345] , n;

int f(int value)
{
    if(value==0){

        return 0;
    }

    if(dp[value]!=-1)return dp[value];
    int v = INT_MAX;

    for(int j=100;j>=1;j--){
        if(value-j*j>=0)v = min(v , f(value-j*j ) + 1);
    }

    return dp[value] = v;
}

int main(void)
{
    int t;
    cin >> t;
    memset(dp , -1 , sizeof(dp));

    while(t--){

        cin >> n;

        cout << f(n) << endl;
    }

    return 0;
}
