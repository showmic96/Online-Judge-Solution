// In the name the Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(void)
{
    int t , c = 0;
    scanf("%d",&t);
    while(t--){

        ll n;
        scanf("%lld",&n);
        printf("Case %d: %lld",++c , n);
        n/=10;
        while(n){
            printf("%lld", n%10);
            n/=10;
        }
        printf("\n");
    }
    return 0;
}
