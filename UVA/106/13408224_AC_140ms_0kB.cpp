// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(void)
{
    ll n;
    while(scanf("%lld",&n)==1){

        ll counter = 0 , cc = 0;

        bool mp[n+10];
        for(int i=0;i<=n;i++)mp[i] = false;

        for(ll i=1;i*i<n;i++){

            for(ll j=i+1;i*i+j*j<=n;j+=2){

                if(i*i+j*j>n)break;
                if(__gcd(i , j)!=1)continue;

                ll a = j*j-i*i;
                ll b = 2*i*j;
                ll c = j*j+i*i;

                counter++;

                ll t1 = a , t2 = b , t3 = c;

                while(t3<=n){

                    if(mp[t1]==0)cc++;
                    if(mp[t2]==0)cc++;
                    if(mp[t3]==0)cc++;

                    mp[t1] = 1;
                    mp[t2] = 1;
                    mp[t3] = 1;

                    t1+=a;
                    t2+=b;
                    t3+=c;
                }
            }
        }

        printf("%lld %lld\n",counter , n-cc);
    }
    return 0;
}
