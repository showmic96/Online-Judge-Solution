#include<bits/stdc++.h>
typedef long long ll ;
using namespace std;

ll remainder1(ll a)
{
    ll  b=0 , c , d , e , f;

    do{
        b+=a%10;
        a=a/10;
        if(a<10){b+=a;
        a=b;b=0;}
    }while(a>=10);
    return a;
}
int main(void)
{
   char ar[1000],br[1000];ll lar=0 , lbr=0;
   while(gets(ar)){gets(br);lbr=0;lar=0;
    for(ll a=0;a<strlen(ar);a++){
        if(ar[a]>='A'&&ar[a]<='Z')lar+=ar[a]-64;
        if(ar[a]>='a'&&ar[a]<='z')lar+=ar[a]-96;
    }
    for(ll a=0;a<strlen(br);a++){
        if(br[a]>='A'&&br[a]<='Z')lbr+=br[a]-64;
        if(br[a]>='a'&&br[a]<='z')lbr+=br[a]-96;
    }
    double aa=min((double)remainder1(lbr),(double)remainder1(lar))/max((double)remainder1(lbr),(double)remainder1(lar));
    printf("%.2lf %%\n",aa*100);
    //cout << lar << endl << lbr << endl;
   }
   return 0;
}