// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

bool check(int p , int s)
{
    int i = (s / 50) % 475;

    for(int j=0;j<25;j++){

        i = (i * 96 + 42) % 475;
        //cout << i+26 << endl;
        if(i+26==p)return true;
    }
    //cout << endl;
    return false;
}

int main(void)
{
    int p , x , y , x_temp , sh = 0;
    cin >> p >> x >> y;

    x_temp = x;

    while(true){

        if(check(p , x)==true){

                cout << sh << endl;
                return 0;
        }

        while(x_temp-50>=y){

            x_temp-=50;

            if(check(p , x_temp)==true){

                cout << sh << endl;
                return 0;
            }
        }

        x+=100;
        x_temp = x;
        sh++;

    }

    return 0;
}
