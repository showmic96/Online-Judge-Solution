// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAX = 6.5e6+90;

ll ar[MAX+9];
vector<ll>v;

void pre()
{
    memset(ar , 0 , sizeof(ar));
    ll counter = 1;

    for(int i=0;i<=MAX;i++)ar[i] = 1;

    for(ll i=2;i<=MAX;i++){

        for(ll j=i;j<=MAX;j+=i)ar[j]++;
    }

    v.push_back(0);
    for(int i=1;i<=MAX;i++){

        v.push_back(v[i-1]+ar[i]);
    }
}

int main(void)
{
    pre();
    int t;
    scanf("%d",&t);

    while(t--){

        int n;
        scanf("%d",&n);

        int ans = lower_bound(v.begin() , v.end() , n) - v.begin();

        printf("%d\n",ans);
    }

    return 0;
}
