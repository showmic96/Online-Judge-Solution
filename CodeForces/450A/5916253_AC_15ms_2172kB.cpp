#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(void)
{
    ll a , b , c ;
    cin >> a >> b;
    ll d=0,e=0;;
    for(ll i=0;i<a;i++){cin >> c;if(c%b==0)c=c/b;else c=(c/b)+1;if(c>=d){d=c;e=i;}}
    cout << e+1 << endl;
    return 0;
}
