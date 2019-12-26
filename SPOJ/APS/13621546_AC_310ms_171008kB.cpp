// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAX = 1e7+9;
ll ar[MAX+9];
ll ans[MAX+9];

void pre()
{
    for(int i=2;i<=MAX;i++)ar[i] = i;
    ar[0] = ar[1] = 0;

    for(int i=2;i<=MAX;i++){

        if(ar[i]==i){

            for(int j=2*i;j<=MAX;j+=i)ar[j] = min(ar[j] , (ll)i);
        }
    }

    for(int i=2;i<=MAX;i++)ans[i] = ar[i]+ans[i-1];
}

int main(void)
{
    pre();

    int t;
    scanf("%d",&t);
    while(t--){

        int n;
        scanf("%d",&n);
        printf("%lld\n",ans[n]);
    }
    return 0;
}
