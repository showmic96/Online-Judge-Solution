// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
ll n , m;

ll f(ll x)
{
    ll sum = 0;
    for(ll i=x;i<=m;i*=x){

        sum+=m/i;
    }

    return sum;
}

int main(void)
{
    int t , c = 0;
    scanf("%d",&t);
    while(t--){

        map<ll , ll>mp1 , mp2;
        set<ll>st;
        set<ll>::iterator it;

        scanf("%lld %lld",&n , &m);

        ll ans = 1e9 , temp = n;

        for(ll i=2;i*i<=temp;i++){

            if(n%i==0){

                ll t= 1;
                ll counter = 0;
                while(n%i==0){

                    t*=i;
                    n/=i;
                    counter++;
                }

                mp1[i] = counter;
                st.insert(i);
            }
        }

        if(n>1){mp1[n]=1;st.insert(n);}

        temp = m;

        for(ll i=2;i*i<=temp;i++){

            if(m%i==0){

                ll t= 1;
                ll counter = 0;
                while(m%i==0){

                    t*=i;
                    m/=i;
                    counter++;
                }

                mp2[i] = counter;
                st.insert(i);
            }
        }

        if(m>1){mp2[m]=1;st.insert(m);};

        ans = 1;

        for(it=st.begin();it!=st.end();it++){

            ll i = *it;

            if(mp1[i]==mp2[i])continue;
            if(mp1[i]>mp2[i]){

                ans = -1;
                break;
            }

            for(int j=0;j<mp2[i];j++)ans*=i;
        }

        if(ans>0)printf("%lld\n",ans);
        else printf("NO SOLUTION\n");
    }
    return 0;
}
