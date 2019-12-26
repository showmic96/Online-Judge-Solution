// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

bool is_prime(ll x)
{
    if(x<2)return false;
    if(x==2)return true;
    if(!(x%2))return false;

    for(ll i=3;i*i<=x;i+=2){

        if(x%i==0)return false;
    }

    return true;
}

int main(void)
{
    ll n;
    while(scanf("%lld",&n)==1){

        if(n%2){

            if(is_prime(n-2)==true){

                printf("%lld is the sum of %lld and %lld.\n",n , 2LL , n-2);
            }
            else printf("%lld is not the sum of two primes!\n",n);
        }

        else{
            bool check = false;
            for(ll i=n/2;i>=1;i--){

                if(is_prime(i)&&is_prime(n-i)&&i!=n-i){

                    printf("%lld is the sum of %lld and %lld.\n",n , i , n-i);
                    check = true;
                    break;
                }
            }

            if(check==false)printf("%lld is not the sum of two primes!\n",n);
        }
    }
    return 0;
}