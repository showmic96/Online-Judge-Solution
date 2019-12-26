// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(void)
{
    ll h1 , h2 , a , b , counter = 0 , h1_temp;
    cin >> h1 >> h2 >> a >> b;

    h1_temp = h1;

    while(true){

        h1+=(8*a);
        if(h1>=h2){

            cout << counter << endl;
            break;
        }

        h1-=12*b;
        h1+=4*a;
        counter++;
        if(h1>=h2){

            cout << counter << endl;
            break;
        }

        //counter++;

        if(h1_temp>=h1){

            cout << -1 << endl;
            break;
        }
    }

    return 0;
}
