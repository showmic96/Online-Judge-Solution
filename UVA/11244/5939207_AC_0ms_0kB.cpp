#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(void)
{
    ll a , b ;
    while(cin >> a >> b){if(!a&&!b)break;
    char ar[a+1][b+1];scanf("\n");
    for(ll c=0;c<a;c++)gets(ar[c]);ll k=0;
    for(ll c=0;c<a;c++)
    for(ll d=0;d<b;d++){
        if(ar[c][d]=='*'&&ar[c][d+1]!='*'&&ar[c][d-1]!='*'&&ar[c+1][d]!='*'&&ar[c+1][d+1]!='*'&&ar[c+1][d-1]!='*'&&ar[c-1][d]!='*'&&ar[c-1][d+1]!='*'&&ar[c-1][d-1]!='*')k+=1;
    }
    cout << k << endl;
    }
    return 0;
}
