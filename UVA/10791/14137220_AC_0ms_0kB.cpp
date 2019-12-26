// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

bitset<1000005>isPrime;
vector<ll>primes;

void seive()
{
    for(int i=0;i<1000005;i++)isPrime[i] = 1;

    for(int i=2;i<1000005;i++){

        if(isPrime[i]==1){

            for(int j=2*i;j<1000005;j+=i){

                isPrime[j] = 0;
            }
            primes.push_back(i);
        }
    }
}

int main(void)
{
    seive();
    ll tc = 0 , n;
    while(cin >> n){

        if(n==0)break;
        if(n==1){

            cout << "Case " << ++tc << ": " << 2 << endl;
            continue;
        }
        ll ans = 0 , w = n , c = 0;
        for(int i=0;primes[i]*primes[i]<=n;i++){

            if(n%primes[i]==0){

                ll counter = 0;
                c++;

                while(n%primes[i]==0){

                    counter++;
                    n/=primes[i];
                }

                ll temp = 1;
                for(int j=0;j<counter;j++)temp*=primes[i];
                ans+=temp;
            }
        }

        if(n>1){ans+=n;c++;}
        if(c==1)ans++;
        cout << "Case " << ++tc << ": " << ans << endl;
    }

    return 0;
}
