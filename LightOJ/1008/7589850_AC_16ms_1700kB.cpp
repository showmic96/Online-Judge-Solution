// In the name of Allah the most Merciful .

#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(void)
{
    int t;
    ll a;

    cin >> t;

    for(int i=0;i<t;i++){

        cin >> a;

        printf("Case %d: ",i+1);

        ll sqrts = ceil(sqrt(a));

        if(a==1){

            cout << 1 << " " << 1 << endl;
        }

        else if((double)sqrt(a)==(ll)sqrt(a)){

            if(a%2==1)cout << 1 << " " << sqrts << endl;
            else cout << sqrts << " " << 1 << endl;
        }

        else{

            ll mid = ((sqrts-1)*(sqrts-1) + 1+(sqrts*sqrts))/2;

            //cout << mid << endl;

            if(a==mid){

                cout << sqrts << " " << sqrts << endl;
            }

            else if(a>mid){

                if((sqrts*sqrts)%2==0){

                    cout << sqrts << " " << (sqrts)*(sqrts) - a+1 << endl;

                }

                else{

                    cout << sqrts*sqrts+1 - a << " " << sqrts << endl;
                }
            }

            else{

                if((sqrts*sqrts)%2==1){

                    cout << sqrts << " " << a - (sqrts-1)*(sqrts-1) << endl;

                }

                else{

                    cout << sqrts - (mid - a) << " " << sqrts << endl;
                }
            }
        }
    }

    return 0;
}
