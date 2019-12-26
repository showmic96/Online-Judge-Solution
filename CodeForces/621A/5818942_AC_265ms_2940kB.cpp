#include<bits/stdc++.h>

typedef long long ll;
using namespace std;

int main()
{
    ll a , b,  c ,d ,e , f, g , h;
    cin >> a;
    ll ar[a];
    c=0;d=0;
    for(b=0;b<a;b++){cin >> ar[b];d+=ar[b];if(ar[b]%2!=0)c+=1;}
    sort(ar,ar+a);
    if(c%2==0)cout << d << endl;
    else for(b=0;b<a;b++)if(ar[b]%2!=0) {cout << d-ar[b] << endl;break;}

    return 0;
}
