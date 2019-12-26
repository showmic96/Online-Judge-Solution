// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

bool isPrime[123456+9];
vector<ll>primes;
ll dp[233][30][1123];
int si , n ,k ;

void seive()
{
    for(int i=0;i<=1234;i++)isPrime[i] = true;
    for(ll i=2;i<=1234;i++){

        for(int j=2;i*j<=1234;j++){

            if(isPrime[i]==true)isPrime[i*j] = false;
        }

        if(isPrime[i]==true){primes.push_back(i);}
    }

    si = primes.size();
    //cout << si << endl;
}

ll f(int i , int j ,int value)
{
    if(j==k){

        if(value==n)return 1;
        return 0;
    }
    if(i==si)return 0;

    if(dp[i][j][value]!=-1)return dp[i][j][value];

    ll v = 0;

    v+=f(i+1 , j , value);
    if(value+primes[i]<=n)v+=f(i+1 , j+1 , value+primes[i]);

    /*for(int k=0;k<si;k++){

        if(value+primes[k]<=n){

            v+=f(i+1 , j+1 , value + primes[k]);
        }
    }*/

    return dp[i][j][value] = v;
}

int main(void)
{
    seive();

    while(cin >> n >> k){

        if(!n&&!k)break;
        memset(dp , -1 , sizeof(dp));
        cout << f(0 , 0 , 0) << endl;
    }

    return 0;
}
