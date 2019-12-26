#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

ll GCD(ll i , ll j)
{
    if(j==0)return i;
    else return GCD(j, i%j);
}


int main(void)
{
    ll a;
    while(cin >> a){if(a==0)break;ll G;
        G=0; ll i , j;
    for(i=1;i<a;i++)
    for(j=i+1;j<=a;j++)
    G+=GCD(i,j);

    cout << G << endl;


    }
    return 0;
}
