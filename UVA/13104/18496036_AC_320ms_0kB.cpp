// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll MOD = 1e9+7;
bitset<10005>bs;

void sieve()
{
    bs&=0;
    bs[0] = 1;
    bs[1] = 1;
    for(int i=2;i<=10000;i++){

        if(bs[i]==0){

            for(int j=2*i;j<=10000;j+=i)bs[j] = 1;
        }
    }
}

char ar[505];
ll dp[505][505*9][2] , si;

ll f(int i , int tot , int smaller)
{
    if(i==si){

        if(bs[tot]==0)return 1;
        return 0;
    }
    if(dp[i][tot][smaller]!=-1)return dp[i][tot][smaller];
    ll value = 0;

    int lim = ar[i]-'0';
    if(smaller==1)lim = 9;

    for(int j=0;j<=lim;j++){

        if(j==lim){

            value+=f(i+1 , tot+j , smaller);
        }
        else{

            value+=f(i+1 , tot+j , 1);
        }
    }

    return dp[i][tot][smaller] = value%MOD;
}

int main(void)
{
    sieve();
    while(scanf("%s",&ar)==1){

        memset(dp , -1 , sizeof(dp));
        si = strlen(ar);
        ll ans = f(0 , 0 , 0) , sum = 0;
        for(int i=0;i<si;i++)sum+=ar[i]-'0';
        if(bs[sum]==0)ans--;
        scanf("%s",&ar);
        si = strlen(ar);
        memset(dp , -1 , sizeof(dp));
        ans = f(0 , 0 , 0) - ans;
        ans+=MOD;
        ans%=MOD;

        printf("%lld\n",ans);
    }
    return 0;
}
