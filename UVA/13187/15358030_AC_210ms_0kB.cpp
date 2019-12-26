// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(void)
{
    int t;
    scanf("%d",&t);
    while(t--){

        ll n;
        scanf("%lld",&n);
        n = n*n + 2LL*n;
        printf("%lld\n",n);
    }
    return 0;
}
