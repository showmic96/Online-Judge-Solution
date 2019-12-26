// In the name of Allah the most Merciful.

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll gcd(ll a  , ll b)
{
    if(a%b==0)return b;
    else return gcd(b , a%b);
}

int main(void)
{
    //cout << gcd(3, 5) << endl;
    ll t , in1 , in2;
    cin >> t;
    while(t--){
        cin >> in1 >> in2;
        if(gcd(in1 , in2)>1)cout << "Sim" << endl;
        else cout << "Nao" << endl;
    }
    return 0;
}
