// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAX = 500000 + 9;

bitset<MAX+9>isPrime;

vector<ll>primes;
ll val[MAX+9] , dp[MAX+9];

void pre()
{
    memset(val , 0 , sizeof(val));
    for(int i=0;i<=MAX;i++)isPrime[i] = 1;

    for(int i=2;i<=MAX;i++){

        if(isPrime[i]==1){

            for(int j=2*i;j<=MAX;j+=i){

                isPrime[j] = 0;
            }

            primes.push_back(i);
        }
    }

    for(int i=2;i<=MAX;i++){

        ll temp = i , counter = 0;

        for(int j=0;primes[j]*primes[j]<=temp;j++){

            while(temp%primes[j]==0){

                counter+=primes[j];
                temp/=primes[j];
            }
        }

        if(temp>1)counter+=temp;
        val[i] = counter;
    }
}

int f(int n)
{
    if(n==val[n])return 1;
    if(dp[n]!=-1)return dp[n];

    return dp[n] = f(val[n])+1;
}

int main(void)
{
    pre();
    memset(dp , -1 , sizeof(dp));

    int t , c = 0;
    scanf("%d",&t);

    while(t--){

        int n , m;
        scanf("%d %d",&n , &m);

        if(n>m)swap(n , m);

        int ans = 0;
        for(int i=n;i<=m;i++){

            ans = max(ans , f(i));
        }

        printf("Case #%d:\n%d\n",++c , ans);
    }
    return 0;
}
