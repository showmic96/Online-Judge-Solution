#include<bits/stdc++.h>
//#include<algorithm>
typedef long long ll;
using namespace std;

int main()
{
    ll a , b,  c ,d ,e , f, g , h;
    cin >> a;
    for(b=0;b<a;b++){
        cin >> c >> d;
        ll ar[c] , br[c-1];
        for(e=0;e<c;e++) cin >> ar[e];
        sort(ar,ar+c);
        h=1000000009;
        for(e=0,f=d-1;e<c-d+1;e++,f++)h=min(h,ar[f]-ar[e]);
        cout << h << endl;

        }




    return 0;
}