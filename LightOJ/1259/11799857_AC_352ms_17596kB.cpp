// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

const int MAX = 1e7+9;

bool isPrime[MAX+9];
vector<int>primes;

void seive()
{
    for(int i=0;i<=MAX;i++)isPrime[i] = true;

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
    seive();
    int t , c = 0;
    scanf("%d",&t);
    while(t--){

        int in;
        scanf("%d",&in);

        int counter = 0;

        for(int i=0;primes[i]<=in/2;i++){

            if(isPrime[in-primes[i]])counter++;
        }

        printf("Case %d: %d\n",++c , counter);
    }
    return 0;
}
