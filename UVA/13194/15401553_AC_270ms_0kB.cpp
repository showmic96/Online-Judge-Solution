// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<ll>primes;
bitset<1000005>bs;

void seive()
{
    for(int i=0;i<=1000000;i++)bs[i] = 1;
    for(int i=2;i<=1000000;i++){

        if(bs[i]==1){
            for(int j=2*i;j<=1000000;j+=i)bs[j] = 0;
            primes.push_back(i);
        }
    }
}

int main(void)
{
    seive();

    int t;
    scanf("%d",&t);
    while(t--){

        ll x;
        scanf("%lld",&x);

        ll sum = 1 , temp = x;

        for(ll i=0;primes[i]*primes[i]<=temp;i++){

            if(temp%primes[i]==0){

                ll counter = 1;
                ll c = 1;

                while(temp%primes[i]==0){

                    c*=primes[i];
                    counter+=c;
                    temp/=primes[i];
                }
                sum*=counter;
            }
        }

        if(temp>1){

            sum*=(temp+1LL);
        }
        sum-=x;

        if(sum<x)printf("deficient\n");
        else if(sum==x)printf("perfect\n");
        else printf("abundant\n");
    }
    return 0;
}
