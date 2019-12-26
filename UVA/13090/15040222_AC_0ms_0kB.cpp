// In the name of Allah the Lord of the Worlds. 

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(void)
{
    int t , c = 0;
    scanf("%d",&t);
    while(t--){
        
        ll n , k;
        scanf("%lld %lld",&n ,&k);
        printf("Case %d: %lld\n",++c , (n-1LL)/k);
    }
    return 0;
}