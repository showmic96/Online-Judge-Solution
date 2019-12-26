// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAX = 65000+9;
bool isPrime[MAX+9];

void seive()
{
    for(int i=0;i<=MAX;i++)isPrime[i]=true;
    isPrime[0] = false;
    isPrime[1] = false;

    for(int i=2;i<=MAX;i++){

        if(isPrime[i]==true){

            for(int j=2*i;j<=MAX;j+=i){

                isPrime[j] = false;
            }
        }
    }
}

long long BigMod(long long x, long long y, long long m) {

	long long tmp = x, ans = 1;
	while(y) {
		if(y&1) {
			ans *= tmp;
			ans %= m;
		}
		tmp = tmp*tmp, tmp %= m;
		y >>= 1;
	}
	return ans;
}

int main(void)
{
    seive();

    ll n;
    while(scanf("%lld",&n)==1){

        if(!n)break;
        bool check = false;

        if(isPrime[n]==false)for(int i=2;i<n;i++){

            if(BigMod(i , n , n)!=i){

                check = true;
                break;
            }
        }

        if(isPrime[n]==false&&check==false)printf("The number %lld is a Carmichael number.\n",n);

        else printf("%lld is normal.\n",n);
    }

    return 0;
}
