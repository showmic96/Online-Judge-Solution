// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll MAX = 1e7;
vector<ll>v;

int main(void)
{
    ll sum = 0;

    for(int i=1;;i++){

        sum+=i;
        v.push_back(sum);
        if(sum>MAX)break;
    }

    ll n;

    while(scanf("%lld",&n)==1){

        ll i;

        for(i=0;;i++){

            if(n<=v[i])break;
        }

        if(i%2==1)
            printf("TERM %lld IS %lld/%lld\n",n ,i+1+(n-v[i]) , v[i]-n+1);
        else printf("TERM %lld IS %lld/%lld\n",n  , v[i]-n+1 , i+1+(n-v[i]));
    }

    return 0;
}
