#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

bool checkPrime(ll a)
{
    ll b=sqrt((double)a);
    for(ll c=3;c<=b;c+=2)if(a%c==0)return false;
    return true;
}
int main(void)
{
    ll a , b , c , d , e;
    cin >> a;
    for(b=0;b<a;b++){
        cin >> c >> d;
        if(c<=2){cout << 2 << endl;c=3;}
        if(c%2==0)c++;
        for(;c<=d;c+=2)if(checkPrime(c)==true)cout << c << endl;
        cout << endl;
    }
    return 0;
}
