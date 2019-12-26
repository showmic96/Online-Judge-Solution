// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAX = 35;
int main(void)
{
    int t , c = 0;
    ll a , b;
    while(scanf("%lld %lld",&a , &b)==2){
        if(a==0&&b==0)break;
        printf("Case %d: %lld\n",++c, (a*(a-1)/2)*(b*(b-1)/2));
    }
    return 0;
}
