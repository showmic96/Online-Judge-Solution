#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(void)
{
    ll a , b , c , d , e ,x =1000000;
    ll ar[x+1];
    for(b=0;b<=x;b++)ar[b]=1;
    ar[0]=0;ar[1]=0;
    for(b=2;b<=sqrt(x);b++){
        if(ar[b]==1){
            for(c=2;c*b<=x;c++)ar[c*b]=0;
        }
    }
    ll i , j , k , l , m , n;
    while(cin >> k){if(k==0)break;
    n=0;
       // cin >> k;
        for(l=3,m=k-3;l<=k-3;l++,m--)if(ar[l]==1&&ar[m]==1){n=1;break;}//cout << k << endl;
        if(n)printf("%lld = %lld + %lld",k,l,m);
        else cout <<"Goldbach's conjecture is wrong.";
        cout << endl;
   // }
    }
    return 0;

}
