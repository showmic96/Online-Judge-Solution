// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(void)
{
    int t , c = 0;
    scanf("%d",&t);
    while(t--){

        ll x;
        scanf("%lld",&x);

        if(x%9==0){

            printf("Case %d: %lld %lld\n",++c , x+(x/9)-1 , x+(x/9));
        }

        else{

            printf("Case %d: %lld\n",++c , x+(x/9));
        }
    }
    return 0;
}
