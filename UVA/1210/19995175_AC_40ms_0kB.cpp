// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAX = 10009;
vector<ll>primes;
bool prime[MAX+9];
int dp[1300][MAX][2];

void sieve()
{
    for(int i=0;i<=MAX;i++)prime[i] = true;
    for(int i=2;i<=MAX;i++){
        if(prime[i]==true){
            for(int j=2*i;j<=MAX;j+=i){
                prime[j] = false;
            }
            primes.push_back(i);
        }
    }
}

int f(int i , int n , int now)
{
    if(n==0)return 1;
    if(n<0)return 0;
    if(i==primes.size())return 0;
    if(dp[i][n][now]!=-1)return dp[i][n][now];
    int value = 0;
    if(now==0){
        value+=f(i+1 , n , now);
        value+=f(i+1, n-primes[i] , 1);
    }
    if(now==1){
        value+=f(i+1, n-primes[i] , 1);
    }
    return dp[i][n][now] = value;
}

int main(void)
{
    sieve();
    memset(dp , -1 , sizeof(dp));
    int n;
    while(scanf("%d",&n)==1){
        if(!n)break;
        printf("%d\n",f(0 , n , 0));
    }
    return 0;
}
