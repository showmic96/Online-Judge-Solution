// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAX = 10000000+9;
bool bs[MAX+9];

void sieve()
{
    for(int i=0;i<=MAX;i++)bs[i] = true;
    for(int i=2;i<=MAX;i++){

        if(bs[i]==true){

            for(int j=2*i;j<=MAX;j+=i){

                bs[j] = false;
            }

        }
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    sieve();
    ll n;
    while(cin >> n){

        if(n<8){

            cout << "Impossible." << endl;
            continue;
        }
        else if(n%2==0){

            cout << 2 << " " << 2 << " ";
            n-=4;
        }
        else if(n%2==1){

            cout << 2 << " " << 3 << " ";
            n-=5;
        }

        for(int i=2;i<=n/2;i++){

            if(bs[i]==true&&bs[n-i]==true){

                cout << i << " " << n-i << endl;
                break;
            }
        }
    }

    return 0;
}
