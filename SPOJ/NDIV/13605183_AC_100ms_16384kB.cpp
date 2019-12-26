// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAX = 1e5+9;

bool isPrime[MAX+9];
vector<int>primes;

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

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    sieve();

    int a , b , n , counter = 0;
    cin >> a >> b >> n;

    for(int i=a;i<=b;i++){

        int temp = i , total = 1;

        for(int j=0;primes[j]*primes[j]<=temp;j++){

            if(temp%primes[j]==0){

                int c = 0;

                while(temp%primes[j]==0){

                    temp/=primes[j];
                    c++;
                }

                total*=(c+1);
            }
        }

        if(temp>1)total*=2;

        if(total==n)counter++;
    }

    cout << counter << endl;

    return 0;
}
