// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(void)
{
    ll n;
    cin >> n;

    ll ar[n];

    for(int i=0;i<n;i++)cin >> ar[i];
    sort(ar , ar+n);

    if(n==1){

        cout << -1 << endl;
    }

    else if(n==2){

        if(ar[0]==ar[1])cout << 1 << endl << ar[0] << endl;
        else if((ar[1]-ar[0])%2==0){

            cout << 3 << endl;
            int t1 = ar[0] - (ar[1]-ar[0]);
            int t2 = ar[1] + (ar[1]-ar[0]);

            cout << t1 << " " << ar[0] + (ar[1]-ar[0])/2 << " " << t2 << endl;
        }
        else{

            cout << 2 << endl;
            int t1 = ar[0] - (ar[1]-ar[0]);
            int t2 = ar[1] + (ar[1]-ar[0]);

            cout << t1 << " " << t2 << endl;
        }
    }
    else{

        int temp = min(ar[1] - ar[0] , ar[n-1] - ar[n-2]);
        int counter = 0;
        int store;

        for(int i=1;i<n;i++){

            if(ar[i-1]+temp!=ar[i]){

                if(ar[i-1]+temp+temp==ar[i]){
                    counter++;
                    store = ar[i-1]+temp;
                }
                else counter = 1e6;
            }
        }

        if(counter==1)cout << 1 << endl << store << endl;
        else{

            bool check = true;

            for(int i=0;i<n-1;i++)if(ar[i]!=ar[i+1])check = false;

            if(check==true)cout << 1 << endl << ar[0] << endl;
            else if(counter>1)cout << 0 << endl;
            else{

                cout << 2 << endl;
                int t1 = ar[0] - (ar[1]-ar[0]);
                int t2 = ar[n-1] + (ar[1]-ar[0]);

                cout << t1 << " " << t2 << endl;
            }
        }
    }

    return 0;
}
