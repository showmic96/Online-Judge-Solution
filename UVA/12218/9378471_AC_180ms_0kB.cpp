// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAX = 1e7+10;

bool isPrime[MAX+9];

void seive()
{
    for(int i=0;i<=MAX;i++)isPrime[i] = true;
    isPrime[0] = false;
    isPrime[1] = false;

    for(ll i=2;i<=MAX;i++){

        for(ll j=2;i*j<=MAX;j++){

            if(isPrime[i]==true)isPrime[i*j] = false;
        }
    }
}

string ar;
map<ll, int>mp;
ll counter , si;

bool taken[10];

void f(ll value)
{
    if(isPrime[value]==true){

        if(mp[value]==0){

            counter++;
            mp[value] = 1;
        }
    }

    for(int i=0;i<si;i++){

        if(taken[i]==false){

            taken[i] = true;

            f(value*10+(ar[i]-'0'));

            taken[i] = false;
        }
    }
}

int main(void)
{
    seive();
    int t;
    scanf("%d",&t);
    while(t--){

        cin >> ar;

        si = ar.size();
        counter = 0;
        mp.clear();

        memset(taken , false, sizeof(taken));

        f(0);

        printf("%lld\n",counter);
    }
    return 0;
}
