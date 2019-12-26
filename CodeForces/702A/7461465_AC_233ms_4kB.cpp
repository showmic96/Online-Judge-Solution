// In the name of Allah the Most Merciful .

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(void)
{
    ll  a , streak = 1 , counter = 1 ,in , pre;
    cin >> a;
    cin >> pre;
    for(ll i=1;i<a;i++){

        cin >> in;

        if(in>pre)counter++;
        else{

            if(streak<counter)streak = counter;
            counter = 1;
        }
        pre = in;
    }
    if(streak<counter)streak = counter;
    cout << streak << endl;

    return 0;
}
