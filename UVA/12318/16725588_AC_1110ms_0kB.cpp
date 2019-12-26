// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll BM(ll a , ll b , ll M)
{
    if(b==0)return 1%M;

    ll x = BM(a , b/2 , M);
    x = (x*x)%M;

    if(b%2==1)x = (x*a)%M;
    return x;
}

int main(void)
{
    ll n , m;
    while(scanf("%lld %lld",&n , &m)==2){

        if(n==0&&m==0)break;
        int p;
        scanf("%d",&p);

        vector<ll>v;

        for(int i=0;i<p+1;i++){

            ll in;
            scanf("%lld",&in);
            v.push_back(in);
        }

        set<ll>st;

        for(ll i=0;i<=m;i++){

            ll now = 0 , temp = 1;

            for(ll j=0;j<p+1;j++){

                now+=(v[j]*temp)%(n+1);
                now%=(n+1);

                temp*=i;
                temp%=(n+1);
            }

            st.insert(now);
        }

        printf("%d\n",(int)st.size());
    }
    return 0;
}
