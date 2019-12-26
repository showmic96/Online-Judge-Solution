#include<bits/stdc++.h>

typedef long long ll ;

using namespace std;
bool primeCheck(ll a)
{
    ll b=sqrt((double)a);
    for (ll c =2 ;c<=b;c++)if(a%c==0)return false;
    return true;
}

int main(void)
{
    char ar[9],br[9];ll b;
    for(ll k=0;k<8;k++){ar[k]=0;br[k]=0;}
    ar[8]='\0';br[8]='\0';
    while(cin>>ar){
        for(ll a=strlen(ar)-1,b =0;b<strlen(ar);a--,b++)br[b]=ar[a];
    ll lar=atoi(ar), lbr=atoi(br);
    if(lar>2&&lar%2==0) cout << lar <<" is not prime."<< endl;
    else if(lar>9&&lar!=lbr&&primeCheck(lar)==true&&primeCheck(lbr)==true) cout << lar << " is emirp." << endl;
    else if(primeCheck(lar)==true)cout << lar << " is prime." << endl;
    else cout << lar <<" is not prime."<< endl;
    for(ll k=0;k<8;k++){ar[k]=0;br[k]=0;}
    ar[8]='\0';br[8]='\0';

    }
    return 0;

}
