// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(void)
{
    ll a , b , c , d;
    while(scanf("%lld %lld %lld %lld",&a , &b , &c , &d)==4){

        ll temp = (12+d-b-c)/3;
        ll rem = (12+d-b-c)%3;

        ll a1 = temp+c;
        ll a2 = temp+b;
        ll a3 = temp;

        if(rem==1&&a+b==c)a1++;
        else if(rem==1)a2++;
        else if(rem==2)a1++,a2++;

        printf("%lld %lld %lld\n",a1 , a2 , a3);
    }
    return 0;
}
