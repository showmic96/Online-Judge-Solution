// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll dp[11][2][10005][83];
ll k , si;

vector<ll>ar;

ll f(int i , int smaller , int value , int sum)
{
    if(i==si){

        if(value==0&&sum==0)return 1;
        return 0;
    }

    if(dp[i][smaller][value][sum]!=-1)return dp[i][smaller][value][sum];

    int lim = 9;
    if(smaller==0)lim = ar[i];

    ll v = 0;

    for(int j=0;j<=lim;j++){

        if(j<lim)v+=f(i+1, 1 , (value*10+j)%k , (sum+j)%k);
        else v+=f(i+1, smaller , (value*10+j)%k , (sum+j)%k);
    }

    return dp[i][smaller][value][sum] = v;
}

void make(ll a)
{
    ar.clear();

    while(a!=0){

        ar.push_back(a%10);
        a/=10;
    }

    if(ar.size()==0)ar.push_back(0);

    si = ar.size();

    reverse(ar.begin() , ar.end());
}

int main(void)
{
    int t;
    scanf("%d",&t);
    while(t--){

        ll a , b;
        scanf("%lld %lld %lld",&a , &b , &k);

        if(k>81){printf("0\n");continue;}

        make(a-1);

        memset(dp , -1 , sizeof(dp));
        ll ans1 = f(0 , 0 , 0 , 0);

        make(b);

        memset(dp , -1 , sizeof(dp));
        ll ans2 = f(0 , 0 , 0 , 0);

        printf("%lld\n" , ans2 - ans1);
    }
    return 0;
}
