#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(void)
{
    char ar[10000];
    while(gets(ar)){
        ar[strlen(ar)]='\0';
        for(ll a=0;a<strlen(ar);){
            ll b=a;
            while(ar[a]!=' '&&a<strlen(ar))a++;
            for(ll c=a-1;c>=b;c--)cout << ar[c];
            if(a<strlen(ar))cout << ' ';
            a++;
        }
        cout << endl;
    }
    return 0;
}