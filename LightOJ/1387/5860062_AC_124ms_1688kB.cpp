#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(void)
{
    ll a , b ,c=0 , d=0 , f =0,e;
    char ar[100];
    cin >> a;
    for(b=0;b<a;b++){
        printf("Case %lld:\n",b+1);
        cin >> c;f=0;
        for(d=0;d<c;d++){
    cin >> ar;
    if(ar[0]=='d'){cin >> e;f+=e;}
    else cout << f << endl;
        }
    }
    return 0;
}
