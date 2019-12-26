// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll dp[205][25][15];
ll n , q , d , m;
vector<ll>v;

ll f(ll i , ll mod , ll c)
{
    if(c==m){

        if(mod==0)return 1;
        return 0;
    }
    if(i>=n)return 0;


    if(dp[i][mod][c]!=-1)return dp[i][mod][c];

    ll value = 0;

    value+=f(i+1 , mod%d , c);
    value+=f(i+1 , ((mod+v[i])%d+d)%d , c+1);

    return dp[i][mod][c] = value;
}

int main(void)
{
    int t , c = 0;
    scanf("%d",&t);
    while(t--){

        v.clear();

        scanf("%lld %lld",&n , &q);

        for(int i=0;i<n;i++){

            ll in;
            scanf("%lld",&in);
            v.push_back(in);
        }

        printf("Case %d:\n",++c);

        while(q--){

            scanf("%lld %lld",&d , &m);

            memset(dp , -1 , sizeof(dp));

            printf("%lld\n",f(0 , 0 , 0));
        }
    }
    return 0;
}
