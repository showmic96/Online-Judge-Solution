// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    ll n , k;

    while(cin >> n >> k){

        if(n==-1&&k==-1)break;

        ll t1 = (k-1)/2;
        t1 = t1*k - t1*(t1+1);
        ll t2 = n*(n-1)/2;

        ll gcd = __gcd(t1 , t2);

        t1/=gcd;
        t2/=gcd;

        if(t1==0)cout << 0 << endl;
        else if(t1==t2)cout << 1 << endl;
        else cout << t1 << "/" << t2 << endl;
    }
    return 0;
}
