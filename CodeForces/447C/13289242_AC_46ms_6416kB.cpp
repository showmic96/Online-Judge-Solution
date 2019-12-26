// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAX = 1e5+9;

vector<ll>v;
ll sum1[MAX+9] , sum2[MAX+9];
int n;

int main(void)
{
    memset(sum1 , 0 , sizeof(sum1));
    memset(sum2 , 0 , sizeof(sum2));

    v.push_back(0);

    scanf("%d",&n);
    for(int i=0;i<n;i++){

        ll in;
        scanf("%lld",&in);
        v.push_back(in);
    }

    v.push_back(1e9);

    for(int i=1;i<=n;i++){

        sum1[i]+=sum1[i-1];
        if(v[i]>v[i-1])sum1[i]++;
        else sum1[i] = 1;
    }

    for(int i=n;i>=1;i--){

        sum2[i]+=sum2[i+1];
        if(v[i]<v[i+1])sum2[i]++;
        else sum2[i] = 1;
    }

    ll ans = 1;

    for(int i=1;i<=n;i++){

        if(v[i-1]+1<v[i+1])ans = max(ans , sum1[i-1]+1+sum2[i+1]);
        ans = max(sum1[i-1]+1 , ans);
        ans = max(sum2[i+1]+1 , ans);
    }

    printf("%lld\n",ans);

    return 0;
}
