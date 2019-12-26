// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<ll>sum;

int main(void)
{
    int n , m;
    scanf("%d %d",&n , &m);

    for(int i=0;i<n;i++){

        ll in;
        scanf("%lld",&in);
        if(i==0)sum.push_back(in);
        else sum.push_back(in+sum[i-1]);
    }

    ll total = 0;

    for(int i=0;i<m;i++){

        ll in;
        scanf("%lld",&in);
        total+=in;

        if(total>=sum[n-1])total = 0;

        ll ans = lower_bound(sum.begin() , sum.end() , total+1) - sum.begin();
        printf("%lld\n",n-ans);
    }

    return 0;
}
