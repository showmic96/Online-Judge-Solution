// In the name of Allah the most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(void)
{
    ll a , b;

    string ar;
    ll br[1000010];
    ll d;

    while(cin >> ar){

        d = 0;

        sort(ar.begin() , ar.end());


        do{
            if(ar[0]=='0')continue;
            stringstream(ar) >> br[d];

            d++;
        }while(next_permutation(ar.begin() , ar.end()));

        sort(br , br+d);

        bool check = false;

        for(int i=0;i<d;i++){

            for(int j=d-1;j>=i;j--){

                if((br[j]-br[i])%9==0){

                    a = br[j];
                    b = br[i];
                    check = true;
                    break;
                }
            }
            if(check==true)break;
        }
        if(check==false) a = br[0] , b = br[d-1];
        ll c = a-b;

        printf("%lld - %lld = %lld = 9 * %lld\n",a , b , c , c/9);
    }

    return 0;
}
