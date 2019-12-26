// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAX = 1e4+9;
bool isPrime[MAX+9];
vector<int>primes;
ll MOD = 1000000007;

void sieve()
{
    for(int i=0;i<=MAX;i++)isPrime[i] = true;
    for(int i=2;i<=MAX;i++){

        if(isPrime[i]){

            for(int j=2*i;j<=MAX;j+=i)isPrime[j] = false;
            primes.push_back(i);
        }
    }
}

int ar[10005];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    sieve();
    int t;
    cin >> t;

    while(t--){

        memset(ar , 0 , sizeof(ar));
        int n;
        cin >> n;

        for(int i=2;i<=n;i++){

            int temp = i;

            for(int j=0;primes[j]*primes[j]<=temp;j++){

                if(temp%primes[j]==0){

                    int counter = 0;

                    while(temp%primes[j]==0){

                        temp/=primes[j];
                        counter++;
                    }

                    ar[primes[j]] = max(ar[primes[j]] , counter);
                }
            }

            if(temp>1)ar[temp] = max(ar[temp] , 1);
        }

        long long ans = 1;

        for(long long i=0;i<=10000;i++){

            long long temp = 1;

            for(int j=0;j<ar[i];j++){

                temp*=i;
                temp%=MOD;
            }

            ans*=temp;
            ans%=MOD;
        }

        cout << ans << endl;
    }

    return 0;
}
