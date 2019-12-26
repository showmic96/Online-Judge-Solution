// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int ans[] = {0 , 1 , 4 , 6 , 5 , 2};

int main(void)
{
    int t;
    scanf("%d",&t);

    while(t--){

        ll n;
        scanf("%lld",&n);
        printf("%d\n",ans[n%6]);
    }

    return 0;
}
