#include<bits/stdc++.h>
typedef long long ll;
#define pi acos(-1)
using namespace std;

int main (void)
{
    ll x , y , z; double a , b , c;
    cin >> x;
    for(y=0;y<x;y++){
        cin >> a;
        printf("%.2f %.2f\n",(pi*a/5*a/5),(a*a*6/10)-(pi*a/5*a/5));
    }

    return 0;
}
