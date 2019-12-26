// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(void)
{
    int t , c = 0;
    scanf("%d",&t);
    while(t--){

        ll ax , ay , bx , by;
        scanf("%lld %lld %lld %lld",&ax , &ay , &bx , &by);

        printf("Case %d: %lld\n",++c , __gcd(abs(bx-ax) , abs(by-ay))+1);
    }
    return 0;
}
