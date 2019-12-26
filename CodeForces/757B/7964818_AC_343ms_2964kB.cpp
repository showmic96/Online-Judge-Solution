// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAX = 1e5+10;

vector<ll>primes;

bool isPrime[MAX+10];

void sieve()
{
    for(int i=0;i<=MAX;i++)isPrime[i] = true;
    isPrime[0] = false;
    isPrime[1] = true;

    for(int i=2;i<=MAX;i++){

        for(int j=2;i*j<=MAX;j++){

            if(isPrime[i]==true)isPrime[i*j] = false;
        }

        if(isPrime[i]==true)primes.push_back(i);
    }
}

int main(void)
{
    int ar[MAX+10];
    sieve();
    int n;
    cin >> n;

    int si=primes.size();
    for(int i=0;i<n;i++)cin >> ar[i];

    int d = 0 , counter = 1 , temp_counter = 0;

    map<int ,int>mp;

    for(int i=0;i<n;i++){

        int lim = sqrt(ar[i]);

        for(int j=0;primes[j]<=lim;j++){

            if(ar[i]%primes[j]==0){

                while(ar[i]%primes[j]==0)ar[i]/=primes[j];
                mp[primes[j]]++;
                if(mp[primes[j]]>counter)counter=mp[primes[j]];
            }
        }

        if(ar[i]!=1){
            mp[ar[i]]++;
            if(mp[ar[i]]>counter)counter = mp[ar[i]];
        }
    }

    cout << counter << endl;
    return 0;
}
