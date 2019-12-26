#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(void)
{
    ll n , n2 , a , b , c;

    cin >> n >> a >> b >> c;


    if(n%4==0){cout << 0 << endl;return 0;}
    else n2 = (n/4 + 1) * 4;

    n2 = n2 - n;

    //cout << n2 << endl;

    if(n2==1){

        ll min1 = b+c;
        ll min2 = 3*c;
        ll min3 = a;
        cout << min(min1 , min(min2 , min3)) << endl;
    }

    if(n2==2){

        ll min1 = 2*c;
        ll min2 = 2*a;
        ll min3 = b;

        cout << min(min1 , min(min2 , min3)) << endl;
    }

    if(n2==3){

        ll min1 = c;
        ll min2 = 3*a;
        ll min3 = a+b;

        cout << min(min1 , min(min2 ,min3)) << endl;
    }


    return 0;

}
