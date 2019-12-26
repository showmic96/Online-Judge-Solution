#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(void)
{
    ll a , b ,c=0 , d;
    cin >> a;
    for(b=0;b<a;b++){
        double i , j , k;
        cin >> i;
        printf("Case %lld: %.2f\n",b+1,(2*i*2*i-(2*acos(0.0)*i*i)));
    }
    return 0;
}
