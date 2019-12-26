#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(void)
{
    ll a , b ,c=0 , d=0 , f =0,e;
    char ar[10000];
    cin >> ar;
    for(a=0;a<strlen(ar);a++)if(ar[a]=='h'){a++;++c;break;}
    for(;a<strlen(ar);a++)if(ar[a]=='e'){a++;++c;break;}
    for(;a<strlen(ar);a++)if(ar[a]=='l'){a++;++c;break;}
    for(;a<strlen(ar);a++)if(ar[a]=='l'){a++;++c;break;}
    for(;a<strlen(ar);a++)if(ar[a]=='o'){a++;++c;break;}
    if(c==5)cout << "YES" << endl;
    else cout << "NO" << endl;

    return 0;
}
