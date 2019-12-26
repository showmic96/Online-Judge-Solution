// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll mod = 1000000007;
ll ncr[1005][1005];

ll fact[1005];

ll nCr(int n , int c)
{
    if(n==c)return 1;
    if(c==0)return 1;
    if(c==1)return n;

    if(ncr[n][c]!=-1)return ncr[n][c];

    return ncr[n][c] = (nCr(n-1 , c-1)+nCr(n-1 , c))%mod;
}

int main(void)
{

    int t , c = 0;
    scanf("%d",&t);

    fact[0] = 1;

    for(ll i=1;i<=1000;i++){

        fact[i] = (i*fact[i-1])%mod;
    }

    memset(ncr , -1 , sizeof(ncr));

    while(t--){

        int n , m , k;

        scanf("%d %d %d",&n , &m, &k);

        ll ans = 1;

        ans*=fact[n-k];

        for(int i=1;i<=m-k;i++){

            if(i%2==1){

                ans-= nCr(m-k , i)*fact[n-k-i];
            }

            else{

                ans+= nCr(m-k , i)*fact[n-k-i];
            }

            ans = (ans+mod)%mod;
        }

        ans*=nCr(m , k);
        ans = (ans+mod)%mod;


        printf("Case %d: %lld\n",++c , ans);
    }

    return 0;
}
