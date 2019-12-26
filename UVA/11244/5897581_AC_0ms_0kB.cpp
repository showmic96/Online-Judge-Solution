#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(void)
{
    ll a , b ;
    while(cin >> a >> b){
        if(a==0&&b==0)break;
        char ar[a+1][b+1];ll f=0;
        for(ll c=0;c<a;c++)cin >>ar[c];
        for(ll c=0;c<a;c++)
            for(ll d=0;d<b;d++)if(ar[c][d]=='*'&&ar[c][d+1]!='*'&&ar[c][d-1]!='*'&&ar[c+1][d]!='*'&&ar[c+1][d+1]!='*'&&ar[c+1][d-1]!='*'&&ar[c-1][d]!='*'&&ar[c-1][d+1]!='*'&&ar[c-1][d-1]!='*')f++;
        cout << f << endl;
        memset(ar,'\0',sizeof(ar));

    }
    return 0;
}