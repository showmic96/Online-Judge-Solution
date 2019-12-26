// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

const int MAX = 1e6+7;

double data[MAX+9];
double lg[1111];

typedef long long ll;

void pre_process()
{
    data[0] = 2;
    data[1] = log(1);

    for(int i=2;i<=MAX;i++){

        data[i] += log10(i) + data[i-1];
    }

    for(int i=2;i<=1010;i++){

        lg[i] = log10(i);
    }
}

int main(void)
{
    pre_process();
    ll t;
    scanf("%lld",&t);//cin >> t;

    for(int i=0;i<t;i++){

        ll n , b;
        //cin >> n >> b;
        scanf("%lld %lld",&n , &b);

        ll value = ceil(1.00*data[n]/lg[b]);

        if(n==0)value = 1;
        printf("Case %d: %lld\n",i+1 , value);
        //cout << (ll)(value) << endl;
    }
    return 0;
}
