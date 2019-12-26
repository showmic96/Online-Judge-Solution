// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(void)
{
    int t;
    scanf("%d",&t);
    while(t--){

        ll n , x;
        scanf("%lld %lld",&n , &x);

        bool check = false;

        for(ll i=1;i<50;i++){
            ll temp = n*(n-1)/2*i;
            if(temp>x)break;

            temp = x-temp;

            if(temp%n==0&&temp/n>0){

                check = true;
                break;
            }
        }

        if(check==true)printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}
