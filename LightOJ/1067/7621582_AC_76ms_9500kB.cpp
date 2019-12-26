// In the name of Allah the most Merciful .

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pi acos(-1)
const ll MAX = 1e6+10;
ll fact[MAX];

#define MOD 1000003

ll big_mod(ll a , ll p)
{
    if(p==0)return 1%MOD;

    ll x = big_mod(a , p/2);

    x = (x*x)%MOD;
    if(p%2==1)x = (x*a)%MOD;

    return x;
}


void pre_cal()
{
    fact[0] = 1;
    for(int i=1;i<MAX;i++){

        fact[i] = i*fact[i-1];
        fact[i]%=MOD;
    }
}

int main(void)
{
    pre_cal();
    ll n , r , t;
    //cout << fact[3] << endl;
    cin >> t;


    for(int i=0;i<t;i++){

        cin >> n >> r;
        printf("Case %d: ",i+1);

        if(n==0||r==0){cout << 1 << endl;continue;}
        if(r>n){cout << 0 << endl;continue;}

        ll lower_term = ((fact[n-r]%MOD)*fact[r]%MOD)%MOD;

        cout << (fact[n]*big_mod(lower_term , MOD-2))%MOD << endl;
    }

    return 0;
}
