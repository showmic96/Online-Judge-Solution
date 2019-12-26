// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(void)
{
    int t , c = 0;
    scanf("%d",&t);
    while(t--){

        int n;
        vector<ll>v;

        scanf("%d",&n);
        for(int i=0;i<n;i++){

            ll in;
            scanf("%lld",&in);
            v.push_back(in);
        }

        ll gcd = v[0];
        for(int i=0;i<n;i++){

            gcd = __gcd(v[i] , gcd);
        }
        if(v.size()==1)gcd = 1;
        ll dem = 1;
        for(int i=0;i<n;i++){

            ll now = v[i];
            dem*=now;
        }
        dem/=gcd;
        ll upor = 0;

        for(int i=0;i<n;i++){

            upor+=dem/v[i];
        }

        dem*=(ll)n;

        gcd = __gcd(dem , upor);
        dem/=gcd;
        upor/=gcd;

        printf("Case %d: %lld/%lld\n",++c , dem , upor);
    }
    return 0;
}
