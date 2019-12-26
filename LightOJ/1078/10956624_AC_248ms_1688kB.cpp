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
        scanf("%lld %lld",&n , &k);

        ll temp = k, counter = 1;

        temp%=n;

        while(temp!=0){

            temp*=10;
            temp+=k;
            temp%=n;
            counter++;
        }

        printf("Case %d: %lld\n",++c, counter);
    }
    return 0;
}
