// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAX = 2e7 + 9;
int dp[MAX+9];

int f(int n)
{
    if(n==1)return 0;

    if(dp[n]!=-1)return dp[n];

    int v = f(n-1) + 1;

    if(n%2==0)v = min(v ,f(n/2) + 1);
    if(n%3==0)v = min(v , f(n/3) + 1);

    return dp[n] = v;
}

int main(void)
{
    memset(dp , -1 , sizeof(dp));

    int t;
    cin >> t;
    for(int i=0;i<t;i++){

        int n;
        cin >> n;
        printf("Case %d: %d\n",i+1, f(n));
    }

    return 0;

}
