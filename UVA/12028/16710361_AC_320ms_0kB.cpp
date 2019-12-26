#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
ll ar[100005] , sum[100005] , MOD = 1000007;

int main(void)
{
    int t , tc = 0;
    scanf("%d",&t);
    while(t--){

        ll k , c , n;
        scanf("%lld %lld %lld %lld",&k , &c , &n , &ar[0]);

        for(int i=1;i<n;i++){

            ar[i] = (k*ar[i-1]+c)%MOD;
        }

        sort(ar , ar+n);
        reverse(ar , ar+n);

        memset(sum , 0 , sizeof(sum));

        for(int i=n-1;i>=0;i--)sum[i]+=sum[i+1]+ar[i];

        ll ans = 0;

        for(int i=0;i<n-1;i++){

            ans+=abs((n-i)*ar[i]-sum[i]);
        }

        printf("Case %d: %lld\n",++tc , ans);
    }
    return 0;
}
