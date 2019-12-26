// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int k;
    cin >> k;
    if(k>36)cout << -1 << endl;
    else if(k==0)cout << 5 << endl;
    else while(k){

        if(k&1){cout << 6 ;k-=1;}
        else {cout << 8;k-=2;}
        
    }

    cout << endl;

    return 0;
}
