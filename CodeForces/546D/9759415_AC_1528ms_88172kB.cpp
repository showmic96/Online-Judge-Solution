// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAX = 5000005;
bool isPrime[MAX+9];
vector<int>primes;

ll dp[5000005];
ll ans[5000005];

void sieve()
{
    for(int i=0;i<=MAX;i++)isPrime[i] = true;

    for(ll i=2;i<=MAX;i++){

        for(ll j=2;i*j<=MAX;j++){

            if(isPrime[i]==true)isPrime[i*j] = false;
        }

        if(isPrime[i]==true)primes.push_back(i);
    }
}

int f(int i)
{
    if(i==1)return 0;

    if(dp[i]!=-1)return dp[i];

    int lim = sqrt(i);
    int value = 1;
    int temp = i;

    for(int j=0;primes[j]<=lim;j++){

        if(temp%primes[j]==0){

            int counter = 0;

            while(temp%primes[j]==0){

                counter++;
                temp/=primes[j];
            }

            value = f(temp) + counter;
            break;
        }
    }

    return dp[i] = value;
}

int main(void)
{
    sieve();
    int t;
    scanf("%d",&t);
    memset(dp , -1 , sizeof(dp));
    memset(ans , 0 , sizeof(ans));

    for(int i=1;i<5000005;i++){

        ll temp = f(i);
        ans[i] = temp + ans[i-1];
    }

    while(t--){

        int in1 , in2;
        scanf("%d %d",&in1 , &in2);

        printf("%lld\n",ans[in1]-ans[in2]);
    }
    return 0;
}
