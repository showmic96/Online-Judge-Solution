// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll dig(ll x)
{
    ll sum = 0;

    while(x!=0){

        sum+=x%10;
        x/=10;
    }

    return sum;
}

bool Check(ll x)
{
    ll sum1 = dig(x);

    bool check = true;

    ll sum2 = 0;

    for(ll i=2;i*i<=x;i++){

        if(x%i==0){

            int counter = 0;

            while(x%i==0){

                x/=i;
                counter++;
            }

            check = false;
            sum2+=counter*dig(i);

        }
    }

    if(x!=1)sum2+=dig(x);

    if(check==true)return false;
    if(sum1==sum2)return true;
    return false;
}

int main(void)
{
    int t;
    scanf("%d",&t);
    while(t--){

        ll in;
        scanf("%lld",&in);

        for(ll i=in+1;;i++){

            if(Check(i)==true){

                printf("%lld\n",i);
                break;
            }
        }
    }

    return 0;
}
