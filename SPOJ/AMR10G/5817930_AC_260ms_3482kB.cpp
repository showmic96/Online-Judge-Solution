#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
 
int main()
{
    ll a , b,  c ,d ,e , f, g;
    cin >> a;
    for(b=0;b<a;b++){
        cin >> c >> d;
        ll ar[c];
        for(e=0;e<c;e++) cin >> ar[e];
        sort(ar,ar+c);
        if(d==1) cout << 0 << endl;
        else{
        	ll diff = 1000000100; 
        	for(int i = 0, j = d-1; j<c ;i++, j++) diff = min(diff, ar[j]-ar[i]);
        	cout << diff << endl;
        }
 
    }
    return 0;
}