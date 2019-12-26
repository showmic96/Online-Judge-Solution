// In the name of Allah the most Merciful.

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
    int t;
    cin >> t;
    bool print = false;
    while(t--){
        if(print)cout << endl;print=true;
        ll in1 , in2;
        scanf("%lld%lld",&in1, &in2);//cin >> in1 >> in2;
        for(;in1<=in2;in1++){

            ll temp = in1;
            bool check = true;

            for(ll i=2;i*i<=in1;i++){

                if(temp%i==0){

                    check=false;
                    break;
                }
            }

            if(check==true&&temp!=1)cout << temp << endl;
        }
    }

    return 0;
}
