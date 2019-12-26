// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(void)
{
    ll a , b , twoa=0 , twob=0 , threea=0 , threeb=0 , foura=0 , fourb=0 , fivea=0 , fiveb=0;
    cin >> a >> b;

    while(a%2==0){a/=2;twoa++;}
    while(a%3==0){a/=3;threea++;}
    while(a%4==0){a/=4;foura++;}
    while(a%5==0){a/=5;fivea++;}

    while(b%2==0){b/=2;twob++;}
    while(b%3==0){b/=3;threeb++;}
    while(b%4==0){b/=4;fourb++;}
    while(b%5==0){b/=5;fiveb++;}

    if(a==b)cout << abs(twoa-twob) + abs(threea-threeb) + abs(foura-fourb) + abs(fivea-fiveb) << endl;
    else cout << -1 << endl;
    return 0;
}
