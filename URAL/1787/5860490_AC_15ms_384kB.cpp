#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(void)
{
    ll a , b ,c=0 , d=0 , f =0,e;
    cin >> a >> b;

    for(c=0;c<b;c++){cin >> d;f+=d;if(f>=a)f-=a;else f=0;}
    cout << f << endl;

    return 0;
}
