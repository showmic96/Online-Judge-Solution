// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAX = 1e6+900;
bitset<MAX+9>isPrime;
vector<ll>primes;

map<ll , int>mp;

void seive()
{
    for(int i=0;i<=MAX;i++)isPrime[i] = 1;
    for(int i=2;i<=MAX;i++){

        if(isPrime[i]==1){

            for(int j=2*i;j<=MAX;j+=i)isPrime[j] = 0;

            primes.push_back(i);
        }
    }

    for(int i=0;i<primes.size();i++){

        ll temp = primes[i];
        temp = temp*temp;
        mp[temp] = 1;
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    seive();

    int n;
    cin >> n;

    while(n--){

        ll x;
        cin >> x;

        map<ll,int>::iterator it = mp.find(x);

        if(it!=mp.end())cout << "YES" << endl;
        else cout << "NO" << endl;
    }

    return 0;
}
