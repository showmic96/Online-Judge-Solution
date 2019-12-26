// In the name of Allah the Lord of the worlds .

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(void)
{
    ll a;
    cin >> a;

    if(a==1||a==2)cout << -1 << endl;
    else {

        if(a%2==0){

            cout << ((a*a)/4-1) << " " << ((a*a)/4+1) << endl;

        }

        else {

            cout << (((a*a)-1)/2) << " " << (((a*a)+1)/2) << endl;
        }
    }

    return 0;
}
