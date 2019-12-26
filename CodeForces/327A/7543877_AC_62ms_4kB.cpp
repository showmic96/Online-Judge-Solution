// In the name of Allah the most Merciful

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(void)
{
    int ar[110] , a , hi = 0;
    cin >> a;
    if(a==1){

        int in;
        cin >> in;

        if(in==1)cout << 0 << endl;
        else cout << 1 << endl;

        return 0;
    }
    for(int i=0;i<a;i++)cin >> ar[i];

    for(int i=0;i<a;i++){

        for(int j=i;j<a;j++){

            int counter = 0;
            for(int k=0;k<a;k++){

                if(k>=i&&k<=j){
                    if(ar[k]==0)counter++;
                    //else counter--;
                }
                else {
                    if(ar[k]==1)counter++;
                }
            }

            if(counter>hi)hi = counter;
        }
    }
    cout << hi << endl;
    return 0;
}


