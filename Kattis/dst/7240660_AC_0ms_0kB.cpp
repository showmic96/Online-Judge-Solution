#include<bits/stdc++.h>
using namespace std;

#define limit 24*60

int main(void)
{
    char x;
    int a , b , c , i;

    cin >> i;

    while(i--){

        cin >> x >> a >> b >> c;

        b = b*60 + c;

        if(x=='B'){

            b -= a;

            //cout << b << endl;

            if(b<0){

                cout << (limit+b)/60  << " " << (limit+b)%60 << endl;
            }


            else cout << b/60 << " " << b%60 << endl;
        }

        if(x=='F'){

            b+=a;

            if(b>limit){

                cout << (b/60) - 24 << " " << b%60 << endl;
            }

            else if(b==limit){

                cout << 0 << " " << 0 << endl;
            }

            else cout << b/60 << " " << b%60 << endl;
        }
    }
    return 0;
}
