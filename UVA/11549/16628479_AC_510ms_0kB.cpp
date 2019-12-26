// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

map<ll , int>mp;
ll mod[15];

int main(void)
{
    mod[0] = 1;
    for(int i=1;i<=10;i++){

        mod[i] = mod[i-1]*10LL;
    }
    int t , c = 0;
    scanf("%d",&t);
    while(t--){

        mp.clear();
        ll k , n;
        scanf("%lld %lld",&k , &n);

        ll mx = 0;
        while(true){

            if(mp.find(n)!=mp.end())break;
            mp[n] = 1;
            mx = max(mx , n);
            n = n*n;
            while(n>=mod[k])n/=10;
        }

        printf("%lld\n",mx);
    }
    return 0;
}
