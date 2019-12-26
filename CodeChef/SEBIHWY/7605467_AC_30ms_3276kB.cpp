// In the name of Allah the most Merciful .


#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(void)
{
    ll T ;double s , sg , fg , d , t;

    cin >> T;

    while(T--){

        cin >> s >> sg >> fg >> d >> t;

        d = d * 50;

        t = (d*3600)/(t*1000);

        s = s + t;

        //cout << s << endl;

        if(abs(fg-s)==abs(sg-s))cout << "DRAW" << endl;
        else if(abs(fg-s)>abs(sg-s))cout << "SEBI" << endl;
        else cout << "FATHER" << endl;
    }

    return 0;

}
