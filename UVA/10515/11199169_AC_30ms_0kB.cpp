// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll f(int a , int b)
{
    ll ans = 1;

    for(int i=0;i<b;i++){

        ans*=a;
        ans%=10;
    }

    return ans;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    string ar , br;

    while(cin >> ar >> br){

        if(ar=="0"&&br=="0")break;

        ll a = ar[ar.size()-1] - '0';
        ll b = 0;

        if(br.size()>=2){

            b = br[br.size()-2] - '0';
        }

        b*=10;
        b +=br[br.size()-1] - '0';
        
        if(b==0) b = 100;

        printf("%lld\n",f(a ,b ));
    }

    return 0;
}
