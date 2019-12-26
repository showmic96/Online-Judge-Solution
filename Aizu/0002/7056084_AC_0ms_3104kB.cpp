#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(void)
{
    ll a , b;

    while(cin >> a >> b){

        a = a+b;

        b = 0;

        while(a!=0){
            b++;
            a/=10;
        }

        cout << b << endl;
    }

    return 0;

}
