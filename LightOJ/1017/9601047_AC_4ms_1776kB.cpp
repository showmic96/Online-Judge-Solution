// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll n , w, k;
ll dp[105][105];
vector<ll>v;

ll f(int i , int j)
{
    if(i==n||j==0)return 0;

    if(dp[i][j]!=-1)return dp[i][j];

    ll value1 = 0 , value2 = 0;

    for(int j=i;j<n;j++){

        if(v[j]>v[i]+w)break;
        value1++;
    }

    value1+=f(i+value1 , j-1);
    value2=f(i+1 , j);

    return dp[i][j] = max(value1 , value2);
}

int main(void)
{
    int t , c = 0;
    scanf("%d",&t);
    while(t--){

        v.clear();
        memset(dp , -1 , sizeof(dp));
        scanf("%lld %lld %lld",&n , &w , &k);

        for(int i=0;i<n;i++){

            ll in1 , in2;
            scanf("%lld %lld",&in1 , &in2);
            v.push_back(in2);
        }

        sort(v.begin() , v.end());

        printf("Case %d: %lld\n",++c , f(0 , k));
    }
    return 0;
}
