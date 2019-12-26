// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(void)
{
    int t;
    scanf("%d",&t);
    while(t--){

        ll a , b , c;
        scanf("%lld %lld %lld",&a , &b , &c);

        bool check = false;

        for(ll i=-100;i<=100;i++){

            for(ll j=-100;j<=100;j++){

                ll temp = i*j;
                if(temp==0||b%temp)continue;
                ll k = b/temp;

                if(j<=i||k<=j)continue;

                if(i+j+k==a&&i*i+j*j+k*k==c){

                    printf("%lld %lld %lld\n",i , j , k);
                    check = true;
                    break;
                }
            }

            if(check)break;
        }

        if(check)continue;
        printf("No solution.\n");
    }
    return 0;
}
