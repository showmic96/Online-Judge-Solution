// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAX = 1299709;
vector<int>primes;
bitset<MAX+9>bs;

void sieve()
{
    bs&=0;
    for(int i=2;i<=MAX;i++){

        if(bs[i]==0){

            primes.push_back(i);
            for(int j=2*i;j<=MAX;j+=i)bs[j] = 1;
        }
    }
}

int main(void)
{
    sieve();

    int n;
    while(scanf("%d",&n)==1){

        if(n==0)break;
        if(binary_search(primes.begin() , primes.end() , n)==true)printf("0\n");
        else{

            int ans = *upper_bound(primes.begin() , primes.end() , n) - *--lower_bound(primes.begin() , primes.end() , n);
            printf("%d\n",ans);
        }
    }
    return 0;
}
