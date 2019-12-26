// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(void)
{
    ll n , k;
    cin >> n >> k;

    ll n_temp = n , five = 0 , two = 0;

    while(n%5==0){

        five++;
        n/=5;
    }

    while(n%2==0){

        two++;
        n/=2;
    }

    for(int i=five;i<k;i++){

        n_temp*=5;
    }

    for(int i=two;i<k;i++){

        n_temp*=2;
    }

    cout << n_temp << endl;

    return 0;
}
