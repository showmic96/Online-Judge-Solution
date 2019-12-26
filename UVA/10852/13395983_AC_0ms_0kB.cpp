// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

const int MAX =  1e5+9;
bool isPrime[MAX+9];
vector<int>primes;

void seive()
{
    for(int i=0;i<=MAX;i++)isPrime[i] = true;
    for(int i=2;i<=MAX;i++){

        if(isPrime[i]){

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
    int t;
    scanf("%d",&t);
    while(t--){

        int n;
        scanf("%d",&n);
        int mx = 0 , ans = -1;

        for(int i=0;i<primes.size();i++){

            if(primes[i]>n)break;

            for(int j=1;;j++){

                int temp = primes[i]*j;
                if(temp>n)break;

                int t = primes[i]*(j+1);

                if(temp<=n&&t>n){

                    if(n-temp>mx){

                        mx = n-temp;
                        ans = primes[i];
                    }
                }
            }
        }

        printf("%d\n",ans);
    }
    return 0;
}
