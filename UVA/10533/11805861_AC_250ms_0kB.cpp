// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAX = 1e6+9;

bool isPrime[MAX+9];
vector<int>primes;

void seive()
{
    for(int i=0;i<=MAX;i++)isPrime[i] = true;

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

void f(int value , int sum)
{
    if(value>MAX)return ;

    if(isPrime[value]==true&&isPrime[sum]==true){

        primes.push_back(value);
    }

    for(int i=0;i<=9;i++){

        if(value==0&&i==0)continue;

        f(value*10+i , sum+i);
    }
}

int main(void)
{
    seive();
    f(0 , 0);
    sort(primes.begin() , primes.end());

    int t;
    scanf("%d",&t);

    while(t--){

        int in1 , in2;
        scanf("%d %d",&in1 , &in2);

        int ans = upper_bound(primes.begin() , primes.end() , in2) - lower_bound(primes.begin() , primes.end() , in1);

        printf("%d\n",ans);
    }

    return 0;
}
