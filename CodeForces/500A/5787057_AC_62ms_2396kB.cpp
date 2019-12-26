#include<bits/stdc++.h>
using namespace std;

int main(void)
{   long long a , b , c , d=0 , e , f;
    cin >>a>>b;
    long long ar[a-1];
    for(c=0;c<a-1;c++) cin >> ar[c];
    e=1;
    for(c=0;e<=a-1;c++)
    {
        f=e+ar[e-1];
        e=f;
        if(e==b){d=1;break;}
    }
    if(d==1) cout << "YES" << endl;
    else cout << "NO" << endl;

    return 0;
}
