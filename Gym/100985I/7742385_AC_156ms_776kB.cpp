// In the name of Allah the most Merciful.

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
    ll n , t , t1 , t2;
    cin >> n >> t;
    t1 = t2 = t;
    ll ar[n];

    for(int i=0;i<n;i++)cin >> ar[i];

    int counter1 = 0 , counter2 = 0;
    bool check1 = true , check2 = true;

    for(int i=0;i<n;i++){

        if(check1==true){

            if(t1-ar[i]>=0){
                counter1++;
                t1-=ar[i];
            }
            else check1 = false;
        }

        if(check2==true)
        {
            if(t2-ar[n-i-1]>=0){
                counter2++;
                t2-=ar[n-i-1];
            }
            else check2=false;
        }
    }

    if(counter1>counter2)cout << "Yan" << endl;
    else if(counter1 < counter2)cout << "Nathan" << endl;
    else cout << "Empate" << endl;

    return 0;
}
