// In the name of Allah the Lord of the worlds.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll phi(ll n){

    ll ret = n;

    for(int i=2;i*i<=n;i++){
        if(n%i==0){
            while(n%i==0){
                n/=i;
            }
        ret-=ret/i;

        }

    }
    if(n>1){

        ret-=ret/n;
    }

    return ret;
}

int main(void)
{
    int t;
    cin >> t;

    for(int i=0;i<t;i++){

        ll in1 , in2;
        cin >> in1 >> in2;
        printf("Case %d: ", i+1);

        if(phi(in1)<=phi(in2)){
            cout << "Swapnil lost it" << endl;
        }
        else cout << "Shibli took it" << endl;
    }
    return 0;
}
