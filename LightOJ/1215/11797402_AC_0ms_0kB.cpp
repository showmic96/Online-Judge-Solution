// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll lcm(ll a , ll b)
{
    ll gcd = __gcd(a , b);


    return (a*b)/gcd;
}

int main(void)
{

    int t , c = 0;
    scanf("%d",&t);

    while(t--){

        ll a , b , l;
        scanf("%lld %lld %lld",&a , &b , &l);

        ll x = lcm(a , b);

        if(l%x==0){

            ll ans = l/x;
            ll temp = __gcd(l , ans);

            if(temp==1){

                printf("Case %d: %lld\n",++c,temp);
            }

            else{

                ll ans2 = 1;

                while(temp!=1){

                    temp = __gcd(ans , l);
                    l/=temp;
                    ans2*=temp;
                }

                printf("Case %d: %lld\n",++c,ans2);
            }
        }

        else{

            printf("Case %d: impossible\n",++c);
        }
    }

    return 0;
}
