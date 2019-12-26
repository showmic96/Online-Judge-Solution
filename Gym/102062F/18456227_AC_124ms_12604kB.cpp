// In the name the Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAX = 1000000+9;
bitset<MAX+9>bs , g;
vector<ll>primes;

void sieve()
{
    bs&=0;
    g&=0;
    for(int i=2;i<=MAX;i++){

        for(int j=2*i;j<=MAX;j+=i){

            bs[j] = 1;
            if(bs[i]==1)g[j] = 1;
        }
    }
    for(int i=0;i<=MAX;i++)if(g[i]==1)primes.push_back(i);
}

int main(void)
{
    sieve();
    int t , c = 0;
    scanf("%d",&t);
    while(t--){

        int n;
        scanf("%d",&n);
        int ans = --lower_bound(primes.begin() , primes.end() , n+1) - primes.begin();
        ans = n-ans-1;
        int gcd = __gcd(n , ans);
        printf("Case %d: %d/%d\n",++c , ans/gcd , n/gcd);
    }
    return 0;
}
