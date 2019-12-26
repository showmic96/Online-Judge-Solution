#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(void)
{
    ll a , b ,c=0 , d;
    cin >> a;
    if(a>1)for(b=1;b<=a;b++)c+=b;
    else for(b=a;b<=1;b++)c+=b;
    cout << c << endl;
    return 0;
}
