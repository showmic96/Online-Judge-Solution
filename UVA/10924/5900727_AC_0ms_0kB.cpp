#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
bool primeCheck(ll a)
{
    ll b=sqrt((double)a);
    for(ll c=3;c<=b;c+=2)
    {
        if(a%c==0)return false;
    }
    return true ;
}

int main(void)
{
    ll a , b ;
    char ar[25];
    while(gets(ar)){ll lar =0;
        for(a=0;a<strlen(ar);a++){if(ar[a]>='a'&&ar[a]<='z')lar+=ar[a]-96;
        else if(ar[a]>='A'&&ar[a]<='Z') lar+=ar[a]-38;}
         if(lar>2&&lar%2==0)cout <<"It is not a prime word." << endl;
         else if(lar==1||lar==2)cout << "It is a prime word." << endl;
       else if(primeCheck(lar)==false) cout << "It is not a prime word." << endl;
        else cout << "It is a prime word." << endl;

    }

    return 0;
}
