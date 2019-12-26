// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll n;

    while(cin >> n){

        ll p1 = 0 , p2 = 9;

        for(int i=0;;i++){

            if(n>=p1&&n<=p2){

                if(i%2==0)cout << "Stan wins." << endl;
                else cout << "Ollie wins." << endl;

                break;
            }

            if(i%2==0){

                p1 = p2+1;
                p2*=2;
            }

            else{

                p1 = p2+1;
                p2*=9;
            }
        }
    }

    return 0;
}
