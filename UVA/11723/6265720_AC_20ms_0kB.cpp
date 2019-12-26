#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
    ll a , b , c;int i=1;
    while(cin >> a >> b){

        if(!a&&!b)break;
        c=0;
        if(a%b!=0)c=(a/b);
        else c = (a/b)-1;

        printf("Case %d: ",i);i++;

        if(c<=26)cout << c << endl;
        else cout << "impossible" << endl;
    }

    return 0;

}
