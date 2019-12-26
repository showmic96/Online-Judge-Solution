#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(void)
{
    ll a;
    int counter = 0;
    while(cin >> a){

        if(!a)break;

        if(a%2==0){

            cout << ++counter << ". even " << a/2 << endl;
         }
         else cout << ++counter << ". odd " << a/2 << endl;
     }

    return 0;
}
