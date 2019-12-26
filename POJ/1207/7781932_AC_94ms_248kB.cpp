// In the name of Allah the most Merciful.

#include<iostream>
using namespace std;
typedef long long ll;

int main(void)
{
    ll a , b;
    while(cin >> a >> b){
        ll hi = 0;
        ll a_t = min(a ,b) , b_t = max(a , b);
        for(int i=a_t;i<=b_t;i++){

            ll temp = i , counter = 0;
            while(temp!=1){

                if(temp%2==0)temp/=2;
                else temp = 3*temp + 1;

                counter++;
                if(temp==1)break;
                //cout << "YES" << endl;
            }
            //cout << i << endl;
            if(counter>hi)hi = counter ;
        }

        cout << a << " " << b << " " << hi+1 << endl;
    }

    return 0;
}
