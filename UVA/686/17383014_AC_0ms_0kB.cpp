// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAX = 1000000+9;
bool bs[MAX+9];

void sieve()
{
    for(int i=0;i<=MAX;i++)bs[i] = true;
    for(int i=2;i<=MAX;i++){

        if(bs[i]==true){

            for(int j=2*i;j<=MAX;j+=i){

                bs[j] = false;
            }

        }
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    sieve();
    ll n;
    while(cin >> n){

        if(!n)break;
        int counter = 0;
        for(int i=2;i<=n/2;i++){

            if(bs[i]==true&&bs[n-i]==true){

                counter++;
            }
        }

        cout << counter << endl;
    }

    return 0;
}
