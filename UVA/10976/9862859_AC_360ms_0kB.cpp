// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

bool cmp(ll a , ll b)
{
    return a > b;
}

int main(void)
{
    ll n;
    while(scanf("%lld",&n)==1){

        map<ll,ll>taken;

        vector<ll> v;

        for(int i=1000000;i>n;i--){

            double value = 1.00*(1.00*n*i)/(i-n*1.00)*1.00;

            if((double)value == (ll)value){

                if(taken[(ll)value]==1||taken[i]==1)continue;

                v.push_back((ll)value);
                v.push_back(i);

                taken[(ll)value] = 1;
                taken[i] = 1;
            }
        }
        ll si = v.size();
        sort(v.begin() , v.end() , cmp);
        printf("%lld\n",si/2);

        for(int i=0;i<si/2;i++){
            printf("1/%lld = 1/%lld + 1/%lld\n",n ,max((n*v[i])/(v[i]-n),v[i]) , min(v[i],(n*v[i])/(v[i]-n)));
        }
    }
    return 0;
}
