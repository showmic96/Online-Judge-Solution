// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

bool prime(ll x)
{
    if(x<=1)return false;
    if(x==2)return true;
    if(x%2==0)return false;
    for(ll i=3;i*i<=x;i+=2){
        if(x%i==0)return false;
    }
    return true;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int n;
    cin >> n;
    if(prime(n-2)==true)cout << 2 << " " << n-2 << endl;
    else cout << -1 << endl;
    return 0;
}
