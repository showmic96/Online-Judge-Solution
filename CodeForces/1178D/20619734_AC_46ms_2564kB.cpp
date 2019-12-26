// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAX = 1e6+9;
bool isPrime[MAX+9];
vector<ll>primes;

void sieve()
{
    memset(isPrime , true , sizeof(isPrime));
    for(int i=2;i<=MAX;i++){
        if(isPrime[i]==true){
            for(int j=2*i;j<=MAX;j+=i){
                isPrime[j] = false;
            }
            primes.push_back(i);
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    sieve();
    ll n;
    cin >> n;
    ll ans = *upper_bound(primes.begin() , primes.end() , n-1);
    cout << ans << endl;
    for(int i=0;i<n-1;i++){
        cout << i+1 << " " << i+2 << endl;
    }
    cout << 1 << " " << n << endl;
    ll rem = ans-n;
    int i = 1;
    while(rem>0){
        cout << i << " " << i+2 << endl;
        rem--;
        if(rem==0)break;
        cout << i+1 << " " << i+3 << endl;
        rem--;
        if(rem==0)break;
        i+=4;
    }
    return 0;
}
