#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long LL;

ll fact(ll a)
{
    if(a==1)return 1;

    return (ll)a*fact(a-1);

}

int main(void)
{
    ll a;

    while(cin >> a){

        if(a<0&&abs(a)%2==0)cout << "Underflow!" << endl;
        else if(a<8&&a>=0)cout << "Underflow!" << endl;
        else if(a<14&&a>7)cout << fact(a) << endl;
        else cout << "Overflow!" << endl;
        //else cout << fact(a) << endl;
    }

    return 0;
}
