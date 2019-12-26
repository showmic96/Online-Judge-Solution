// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAX =  1000000+9;

bitset<MAX+9>bs;
vector<ll>primes , ans;

void sieve()
{
    bs&=0;
    for(int i=2;i<=MAX;i++){

        if(bs[i]==0){

            primes.push_back(i);
            for(int j=2*i;j<=MAX;j+=i)bs[j] = 1;
        }
    }
}

ll NOD(ll x)
{
    ll counter = 1;

    for(int i=0;primes[i]*primes[i]<=x;i++){

        if(x%primes[i]==0){

            ll c = 0;
            while(x%primes[i]==0){
                c++;
                x/=primes[i];
            }
            counter*=(c+1LL);
        }
    }

    if(x>1)counter*=2LL;
    return counter;
}

void pre()
{
    sieve();
    ans.push_back(1);

    for(int i=1;;i++){

        ll temp = ans[i-1] + NOD(ans[i-1]);
        ans.push_back(temp);
        if(temp>MAX)break;
    }
}

int main(void)
{
    pre();
    int t , c = 0;
    scanf("%d",&t);
    while(t--){

        ll in1 , in2;
        scanf("%lld %lld",&in1 ,&in2);

        ll a = upper_bound(ans.begin() , ans.end() ,in2) - lower_bound(ans.begin() , ans.end() , in1);
        printf("Case %d: %lld\n",++c , a);
    }
    return 0;
}
