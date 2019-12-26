#include<bits/stdc++.h>
typedef long long ll;
using namespace std;


int main(void)
{
    ll a , b ;
    cin >> a;
    for(b=0;b<a;b++){
        ll c , d,e=0,f;
        cin >> c;
        for(d=0;d<c;d++){cin >>f;e+=f;}
        cout << e << endl;
        if(b!=a-1)cout << endl;
    }




    return 0;
}
