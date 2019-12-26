// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(void)
{
    ll n;
    while(scanf("%lld",&n)==1){

        if(n==0)break;
        vector<ll>v;

        for(int i=0;i<32;i++){

            if(n&(1<<i))v.push_back(i);
        }

        ll a = 0 , b = 0;
        for(int i=0;i<v.size();i++){

            if(i%2==0)a+=(1<<v[i]);
            else b+=(1<<v[i]);
        }
        printf("%lld %lld\n",a , b);
    }
    return 0;
}
