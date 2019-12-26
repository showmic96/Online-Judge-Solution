// In the name of Allah the most Merciful

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(void)
{
    int t;
    cin >> t;
    for(int i=0;i<t;i++){

        ll in;
        cin >> in;
        printf("Case %d: ",i+1);

        if(in==1)cout << 1 << " " << 1 << endl;
        else if((ll)sqrt(in)==(double)sqrt(in)){

            if((ll)sqrt(in)%2==1)cout << "1 " << (ll)sqrt(in) << endl;
            else cout << (ll)sqrt(in) << " 1" << endl;
        }

        else if((ll)sqrt(in)%2==0){
            ll temp = sqrt(in);
            ll temp2 = (temp*temp+(temp+1)*(temp+1)+1)/2;

            if(temp2==in)cout << temp+1 << " " << temp+1 << endl;
            else if(temp2>in){

                cout << temp+1 << " " << temp-(temp2-in)+1 << endl;
            }

            else{

                cout << temp - (in - temp2) +1 << " " << temp+1 << endl;
            }
        }

        else{

            ll temp = (ll)sqrt(in);
            ll temp2 = (ll)(temp*temp+(temp+1)*(temp+1)+1)/2;

            if(temp2==in)cout << temp+1 << " " << temp+1 << endl;
            else if(temp2<in){

                cout << temp+1 << " " << temp-(in-temp2)+1 << endl;
            }

            else{

                cout << temp-(temp2-in)+1 << " " << temp+1 << endl;
            }

        }
    }
    return 0;
}
