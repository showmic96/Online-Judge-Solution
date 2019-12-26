// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int t;
    cin >> t;
    for(int i=0;i<t;i++){

        int n , mx , mi , in1 , in2 , in3;
        string ar , store_mx , store_mi;

        cin >> n;
        n--;

        cin >> ar >> in1 >> in2 >> in3;

        store_mi = ar;
        store_mx = ar;

        mi = in1*in2*in3;
        mx = mi;

        while(n--){

            cin >> ar >> in1 >> in2 >> in3;

            int temp = in1*in2*in3;

            if(temp>mx){

                mx = temp;
                store_mx = ar;
            }

            if(temp<mi){

                mi = temp;
                store_mi = ar;
            }
        }

        printf("Case %d: ",i+1);

        if(mi==mx)cout << "no thief" << endl;
        else {

            cout << store_mx << " took chocolate from " << store_mi << endl;
        }
    }
    return 0;
}
