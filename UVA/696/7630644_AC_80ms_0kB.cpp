// In the name of Allah the Most Merciful .

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(void)
{
    ll a , b;

    while(cin >> a >> b)
    {
        if(!a&&!b)break;

        if(min(a , b)==1){
            cout << max(a , b);
        }
        else if(min(a , b)==2){

            if(max(a , b)%2==1){

                cout << max(a , b) + 1 ;
            }

            else if((max(a,b)/2)%2==1)cout << max(a , b) + 2  ;

            else cout << max(a , b) ;
        }

        else{

            ll aa = a*b;

            if(aa%2==1)cout << aa/2 + 1;
            else cout << aa/2;
        }


        cout << " knights may be placed on a " << a << " row " << b << " column board." << endl;

    }

    return 0;
}
