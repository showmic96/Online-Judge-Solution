#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int n , k;
vector<ll>v;
ll dp[32][32][1002];

ll f(int i , int l , int tot)
{
    if(i==v.size()){

        if(tot==0)return 0;
        if(l==30)return 1;
        if(k-tot<v[l])return 1;
        return 0;
    }

    if(dp[i][l][tot]!=-1)return dp[i][l][tot];
    ll value = 0;

    if(tot+v[i]<=k)value+=f(i+1 , l , tot+v[i]);

    if(l==30)value+=f(i+1 , i , tot);
    else if(v[i]<v[l])value+=f(i+1 , i , tot);
    else value+=f(i+1 , l , tot);

    return dp[i][l][tot] = value;
}

int main(void)
{
    int t , c = 0;
    scanf("%d",&t);
    while(t--){
        v.clear();
        scanf("%d %d",&n , &k);
        for(int i=0;i<n;i++){

            ll in;
            scanf("%lld",&in);
            v.emplace_back(in);
        }

        memset(dp , -1 , sizeof(dp));

        printf("%d %lld\n",++c , f(0 , 30 , 0));
    }

    return 0;
}
