// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<int>primes;

bool is_prime(int x)
{
    if(x<2)return false;
    if(x==2)return true;
    if(x%2==0)return false;

    for(int i=3;i*i<=x;i+=2)if(x%i==0)return false;
    return true;
}

void pre()
{
    for(int i=0;i<=90;i++){

        for(int j=i;j<=90;j++){

            if(is_prime(i*i+j*j)==true)primes.push_back(i*i+j*j);
        }
    }
    sort(primes.begin() , primes.end());
}

ll dp[8000][4];

ll f(int i , int j)
{
    if(i==0)return 1;
    if(i<0)return 0;

    if(dp[i][j]!=-1)return dp[i][j];

    ll value = 0;

    for(int k=1;k<=j;k++){

        value+=f(i-k,k);
    }

    return dp[i][j] = value;
}

int main(void)
{
    pre();

    int t;
    scanf("%d",&t);
    memset(dp , -1 , sizeof(dp));

    while(t--){

        int n , k;
        scanf("%d %d",&n , &k);
        printf("%lld\n",f(primes[n-1], k));
    }
    return 0;
}
