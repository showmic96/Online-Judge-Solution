// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll INF = 1234567891011121314;

int main(void)
{
    ll n , k , p;
    scanf("%lld %lld %lld",&n , &k, &p);

    vector<ll>v1 , v2;

    for(int i=0;i<n;i++){

        ll in;
        scanf("%lld",&in);
        v1.push_back(in);
    }

    for(int i=0;i<k;i++){

        ll in;
        scanf("%lld",&in);
        v2.push_back(in);
    }

    sort(v1.begin() , v1.end());
    sort(v2.begin() , v2.end());

    ll ans = INF;

    for(int i=0;i<k;i++){

        ll temp = 0;

        for(int j=0;j<n;j++){

            if(i+j>=k){temp = INF;break;}
            temp = max(temp , abs(v1[j]-v2[i+j]) + abs(v2[i+j]-p));
        }

        ans = min(temp , ans);
    }

    printf("%lld\n",ans);

    return 0;
}
