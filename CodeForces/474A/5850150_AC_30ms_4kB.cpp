#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

int main (void)
{
    char a1[13]={'q','w','e','r','t','y','u','i','o','p','[',']'};
    char a2[11]={'a','s','d','f','g','h','j','k','l',';'};
    char a3[11]={'z','x','c','v','b','n','m',',','.','/'};
    char b;
    cin >> b;
    char ar[101];
    cin >> ar;
    for(ll a =0;a<strlen(ar);a++){
        for(ll c=0 ; c<12;c++){if(ar[a]==a1[c]){if(b=='R')cout << a1[c-1];else cout << a1[c+1];break;}}
        for(ll c=0 ; c<10;c++){if(ar[a]==a2[c]){if(b=='R')cout << a2[c-1];else cout << a2[c+1];break;}}
        for(ll c=0 ; c<10;c++){if(ar[a]==a3[c]){if(b=='R')cout << a3[c-1];else cout << a3[c+1];break;}}


    }
    cout << endl;

}