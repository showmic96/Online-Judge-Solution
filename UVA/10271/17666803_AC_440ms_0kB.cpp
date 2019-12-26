// In the name the Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll dp[5005][1015];
vector<ll>v;
int n , k;

ll f(int i , int j)
{
    if(j==0)return 0;
    if(i>=n-1)return 1e17;
    if(n-i<3*j)return 1e17;

    if(dp[i][j]!=-1)return dp[i][j];
    ll value = f(i+1 , j);
    value = min(value , f(i+2 , j-1)+(v[i+1]-v[i])*(v[i+1]-v[i]));

    return dp[i][j] = value;
}

int main(void)
{
    int t;
    scanf("%d",&t);
    while(t--){

        v.clear();
        scanf("%d %d",&k , &n);
        for(int i=0;i<n;i++){

            ll in;
            scanf("%lld",&in);
            v.emplace_back(in);
        }

        memset(dp , -1 , sizeof(dp));
        printf("%lld\n",f(0 , k+8));
    }
    return 0;
}
