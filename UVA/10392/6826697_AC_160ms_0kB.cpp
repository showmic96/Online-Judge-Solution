#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAX = 10000010;

bool prime[MAX + 1];
vector<ll>primes;

void seive()
{
    for(int i=0;i<=MAX;i++){

        prime[i]= true;
    }

    for(int i=2;i<=sqrt(MAX);i++){

        for(int j=2;j*i<=MAX;j++){

            if(prime[j]==true)prime[i*j]=false;
        }
    }

    for(int i=2;i<=MAX;i++){

        if(prime[i]==true)primes.push_back(i);
    }
}

bool isPrime(long long a)
{
    if(a%2==0)return false;

    for(int i=3;i<=sqrt(a);i+=2){
        //cout << i << endl;
        if(a%i==0)return false;
    }

    return true;

}


int main(void)
{
    ll a;
    seive();
    while(scanf("%lld",&a)){

        if(a<0)break;

        for(int i=0;i<primes.size();i++){

            if(a%primes[i]==0){


                while(a%primes[i]==0){a/=primes[i];printf("    %d\n",primes[i]);}
            }


        }

        if(a!=1)printf("    %lld\n",a);

        printf("\n");
    }

    return 0;

}
